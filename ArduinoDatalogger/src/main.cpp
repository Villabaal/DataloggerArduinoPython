#include <Arduino.h>
#include <stdint.h>
#include <Timers.h>


uint16_t meassure,count {},n;
byte data[2];
unsigned long lastTimer,T;
static constexpr uint8_t  led {14},entrada {A0};

//using timer 1 template
using timer = Timer<1>;
void sampling();

void setup() {
  Serial.begin(19200);
  pinMode(led,OUTPUT);
  timer::isr = sampling;
}
 
void loop(){
  if (Serial.available() < 3 ) return;
  if ( Serial.read() == 'k'){
    Serial.readBytes(data, 2);
    n = word(data[0],data[1]);  
    Serial.readBytes(data, 2);
    T = word(data[0],data[1]);  
    timer::setInterval( T );
    timer::enableTimer(); return;
  }
  while (Serial.available() > 0 ) Serial.read();  
}

void sampling(){
  digitalWrite(led,!digitalRead(led));
  if ( count < n ){
    meassure = analogRead(entrada);        
    data[0] = highByte(meassure);
    data[1] = lowByte(meassure);
    Serial.write(data[0]); Serial.write(data[1]);
    count++; return;
  }
  count = 0; digitalWrite(led,false); 
  timer::stopTimer();
}