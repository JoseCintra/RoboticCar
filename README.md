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

Where **speed** is the pwm valued (0 to 100). 


To turn the car to the right or left, use the methods:

``car.turnRight(speed);``

or

``car.turnLeft(speed);``

Where **speed** is the pwm valued (0 to 100).


It is also possible to rotate the car on its axis through the methods:
``car.rotateRight(speed);``

or

``car.rotateLeft(speed);``

Where **speed** is the pwm valued (0 to 100).


To stop the car simply use: 
``car.stop();``


Here is also the possibility of creating custom movements, passing the speed and direction of each motor, using the command: 
``car.customDirection(pwm1, dir1, pwm2, dir2);``

For more information see the examples.

# Feedback
Version 0.2.1 Beta Release.
Your feedback is important. Register an issue to request a modification to this software. 

**Thanks!**

![Prototype](https://i.pinimg.com/originals/21/d9/9a/21d99a0a7d1632182bb15655a5ae921f.jpg)
