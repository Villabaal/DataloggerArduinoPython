# Arduino mega data logger
## PlatformIO project and jupiter notebook

The project focuses on:

- Configuring the Arduino Mega for precise reading of analog data from the PT100 sensor.
- Implementing compensation and calibration algorithm to enhance the accuracy of temperature readings.
- Serial communication interface for data transfer to a computer.
- Data analysis using Python for processing and visualization.
- Designing and implementing a Butterworth low-pass digital filter to smooth temperature readings.

## Repo structure

- **/ArduinoDatalogger**: Contains the C++ source code for the Arduino Mega.
- **Notes.ipynb**: Python scripts for signal analysis.


##  Work's overview


1. The Wheatstone bridge was designed to preamplify and prefilter the temperature signal.
2. The Arduino Mega was used to collect readings using the ADC.
3. Using the `serial` module, the number of samples and the sampling period of the signal are set.
4. With the `pandas` module, data is documented with timestamps and saved to a CSV file.
5. The fast Fourier transform from the `scipy` module is utilized, and with `matplotlib`, visualization is obtained to estimate the cutoff frequency to be used in the digital filter.
6. With simpy, the z-transform of a 3rd order Butterworth filter is obtained, and by specifying the chosen sampling time and cutoff frequency, the difference equation of the filter is obtained.


![wheatstone bridge](/wheatstone.png)
<div align="center">Pt100 Preamp</div>