# RoboticCar
Arduino library for controlling the movements of a 2wd robotic car using a H-bridge motor driver L298P


# Install the library

Download this repository as a .zip file and from the Arduino IDE go to Sketch -> Include library -> Add .ZIP Library
Then insert the "include statement" in your code:

``#include <RoboticCar.h>`` 

And create an instance of the library:

``RoboticCar car(pwm1, dir1, pwm2, dir2);``

Where:
- **pwm1** is pwm pin to control the speed of motor 1
- **dir1** is a pin to control the direction (forward or backward) of motor 1
- **pwm2** is pwm pin to control the speed of motor 2
- **dir2** is a pin to control the direction (forward or backward) of motor 2

# Methods

To drive the car forwards or backwards, use the methods:
``car.goAhead(speed);``
or
``car.goBack(speed);``

Where **speed** is the pwm speed (0 to 100) 
