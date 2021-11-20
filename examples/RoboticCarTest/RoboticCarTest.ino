/*
  Robotic Car Test

  Created November 2021 by José Cintra
  https://josecintra.com/blog
  https://github.com/JoseCintra/RoboticCar

*/

/* Libraries
 ************/
#include <RoboticCar.h>
RoboticCar car(10, 12, 11, 13);

/* Setup
 ********/
void setup() {
  delay(10000);
  Serial.begin(9600);
}

/* Loop
 *******/
void loop() {
  car.goAhead(100);   
  delay(3000);         
  car.stop();       
  delay(3000);      
  car.goBack(100);   
  delay(3000);
  car.stop();       
  delay(3000);        
  car.turnLeft(100);   
  delay(3000);         
  car.stop();       
  delay(3000);    
  car.turnRight(100);   
  delay(3000);         
  car.stop();       
  delay(3000);  
  car.rotateLeft(100);   
  delay(3000);         
  car.stop();       
  delay(3000);  
  car.rotateRight(100);   
  delay(3000);         
  car.stop();       
  delay(3000);      
}