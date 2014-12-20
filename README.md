# RTIMULib-Teensy - a versatile 9-dof and 10-dof IMU library for the Teensy3.1

RTIMULib-Teensy is the simplest way to connect a 9-dof or 10-dof IMU to a Teensy3.1 and obtain fully fused quaternion or Euler angle pose data.

Check out www.richards-tech.com for more details, updates and news.

RTIMULib-Teensy currently supports the following IMUs:

* InvenSense MPU-9150 single chip IMU.
* InvenSense MPU-9250 single chip IMU (I2C and SPI)
* STM LSM9DS0 single chip IMU
* L3GD20H + LSM303D (optionally with the LPS25H) as used on the Pololu AltIMU-10 v4.
* L3GD20 + LSM303DLHC as used on the Adafruit 9-dof (older version with GD20 gyro) IMU. 
* L3GD20H + LSM303DLHC (optionally with BMP180) as used on the new Adafruit 10-dof IMU.

Pressure/temperature sensing is supported for IMUs fitted with the BMP180 and LPS25H sensors provided both IMU and pressure sensor are on the I2C bus.

By default, RTIMULib will try to auto-discover IMUs and pressure sensors on I2C and SPI busses (only IMUs on the SPI bus). By default, the SPI IMU interface uses Teensy3.1 pin 9 as the chip select but this can be changed by editing libraries/RTIMULib/RTIMUSettings.h.

RTIMULib also supports multiple sensor integration fusion filters such as Kalman filters.

In order to store calibration data (and use TeensyMagCal), it is necessary to have an SD card available to the Teensy3.1. This uses the SPI interface and pin 10 as select by default. This can be changed by editing libraries/RTIMULib/RTIMUSettings.h.

Configuration will be stored in a file called RTIMULib.ini on the SD card. This can be edited by hand (on another machine with an SD card reader) if there is any need to change defaults or auto-detection settings. A simple sketch is provided that deletes this file if necessary - changing IMU type would be an example. The RTIMULib.ini file could be edited but it's quicker to just delete the ini file and start again if the IMU type is changed.

The actual RTIMULib and support libraries are in the library directory. The other top level directories contain example sketches.

*** Important note ***
It is essential to calibrate the magnetometers or else very poor results will obtained, especially with the MPU-9150 and MPU-9250. If odd results are being obtained, suspect the magnetometer calibration! Operating without calibration (which requires an SD card) can be done but is not recommended.

## The Example Sketches

### Build and run

To build and run the example sketches, start the Teensyduino IDE and use File --> Preferences and then set the sketchbook location to:

	.../RTIMULib-Teensy

where "..." represents the path to the RTIMULib-Teensy directory. The directory is set up so that there's no need to copy the libraries into the main Arduino libraries directory although this can be done if desired.

### TeensyMagCal

This sketch can be used to calibrate the magnetometers and should be run before trying to generate fused pose data. It also needs to be rerun at any time that the configuration is changed (such as different IMU or different IMU reference orientation). Load the sketch and waggle the IMU around, making sure all axes reach their minima and maxima. The display will stop updating when this occurs. Then, enter 's' followed by enter into the IDE serial monitor to save the data.

### TeensyIMU

TeensyIMU is the main demo sketch. It configures the IMU based on settings in RTIMUSettings.cpp. Change these to alter any of the parameters or edit the RTIMULib.ini file after auto-detection.


### TeensyIMU10

This is exactly the same as TeensyIMU except that it adds support for a pressure sensor. If a pressure sensor was found during auto-detection, this will be used by the sketch. If not pressure sensors were found, the sketch will report this and stop.


### TeensyAccel

This is similar to TeensyIMU except that it subtracts the rotated gravity vector from the accelerometer outputs in order to obtain the residual accelerations - i.e. those not attributable to gravity.

### TeensyDeleteIni

A simple sketch that can be downloaded to delete the RTIMULib.ini file from the SD card.

## Release history

### December 20 2014 - 1.0.0

Initial version.