/*
RoboticCar
Arduino library for controlling the movements of a 2wd robotic car using a H-bridge motor driver L298P

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

#ifndef RoboticCar_h
#define RoboticCar_h

#include <Arduino.h>

class RoboticCar {

  public:
    RoboticCar(uint8_t speedPinLeft, uint8_t directionPinLeft, uint8_t speedPinRight, uint8_t directionPinRight); 
    void goAhead(uint8_t speed); 
    void goBack(uint8_t speed);
    void turnLeft(uint8_t speed);  
    void turnRight(uint8_t speed);  
    void stop();  
    void rotateLeft(uint8_t speed);  
    void rotateRight(uint8_t speed);  
    void customDirection(uint8_t speedLeft, uint8_t directionLeft, uint8_t speedRight, uint8_t directionRight); 

  private:
    uint8_t speedAdjust(uint8_t speed);
    uint8_t _speedPinLeft;
    uint8_t _directionPinLeft;
    uint8_t _speedPinRight;
    uint8_t _directionPinRight;
    const uint8_t FORWARD = 1;
    const uint8_t BACKWARD = 0;
    const uint8_t STOP = 0;
    const uint8_t MIN_SPEED = 27;
    const uint8_t MAX_SPEED = 100;
};

#endif
