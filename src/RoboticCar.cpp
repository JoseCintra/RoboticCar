/*
RoboticCar
Arduino library for controlling the movements of a 2wd robotic car using a H-bridge motor driver L298P
Version 0.2.1 Beta Reliease

November 2021 by José Cintra
https://josecintra.com/blog
https://github.com/JoseCintra/RoboticCar


This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <https://unlicense.org>
*/

#include "RoboticCar.h"
#include <Arduino.h>

RoboticCar::RoboticCar(uint8_t speedPinLeft, uint8_t directionPinLeft, uint8_t speedPinRight, uint8_t directionPinRight) {
  _speedPinLeft = speedPinLeft;
  _directionPinLeft = directionPinLeft;
  _speedPinRight = speedPinRight;
  _directionPinRight = directionPinRight;

  pinMode(_speedPinLeft, OUTPUT);
  pinMode(_directionPinLeft, OUTPUT);
  pinMode(_speedPinRight, OUTPUT);
  pinMode(_directionPinRight, OUTPUT);
}

void RoboticCar::goAhead(uint8_t speed) {
  stop();
  speed = speedAdjust(speed);
  digitalWrite(_directionPinLeft, FORWARD);
  analogWrite(_speedPinLeft, speed);
  digitalWrite(_directionPinRight, FORWARD);
  analogWrite(_speedPinRight, speed);
}

void RoboticCar::goBack(uint8_t speed) {
  stop();
  speed = speedAdjust(speed);
  digitalWrite(_directionPinLeft, BACKWARD);
  analogWrite(_speedPinLeft, speed);
  digitalWrite(_directionPinRight, BACKWARD);
  analogWrite(_speedPinRight, speed);
}

void RoboticCar::stop() {
  analogWrite(_speedPinLeft, STOP);
  analogWrite(_speedPinRight, STOP);
}

void RoboticCar::turnLeft(uint8_t speed) {
  stop();
  speed = speedAdjust(speed);
  digitalWrite(_directionPinLeft, FORWARD);
  analogWrite(_speedPinLeft, speedAdjust(speed * 2 / 3));
  digitalWrite(_directionPinRight, FORWARD);
  analogWrite(_speedPinRight, speed);
}

void RoboticCar::turnRight(uint8_t speed) {
  stop();
  speed = speedAdjust(speed);
  digitalWrite(_directionPinLeft, FORWARD);
  analogWrite(_speedPinLeft, speed);
  digitalWrite(_directionPinRight, FORWARD);
  analogWrite(_speedPinRight, speedAdjust(speed * 2 / 3));
}

void RoboticCar::rotateLeft(uint8_t speed) {
  stop();
  speed = speedAdjust(speed);
  digitalWrite(_directionPinLeft, BACKWARD);
  analogWrite(_speedPinLeft, (speed));
  digitalWrite(_directionPinRight, FORWARD);
  analogWrite(_speedPinRight, speed);
}

void RoboticCar::rotateRight(uint8_t speed) {
  stop();
  speed = speedAdjust(speed);
  digitalWrite(_directionPinLeft, FORWARD);
  analogWrite(_speedPinLeft, (speed));
  digitalWrite(_directionPinRight, BACKWARD);
  analogWrite(_speedPinRight, speed);
}

void RoboticCar::customDirection(uint8_t speedLeft, uint8_t directionLeft, uint8_t speedRight, uint8_t directionRight) {
  stop();
  speedLeft = speedAdjust(speedLeft);
  speedRight = speedAdjust(speedRight);
  digitalWrite(_directionPinLeft, directionLeft);
  analogWrite(_speedPinLeft, (speedLeft));
  digitalWrite(_directionPinRight, directionRight);
  analogWrite(_speedPinRight, speedRight);
}

uint8_t RoboticCar::speedAdjust(uint8_t speed) {
  speed = (speed > 100) ? 100 : speed;
  speed = map(speed, 0, MAX_SPEED, MIN_SPEED, 255);
  return speed;
}

