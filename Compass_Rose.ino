/*
  copyright(c) Charles Shapiro October 2017
  
  This file is part of the Compass Rose project

    Compass Rose is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Foobar is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Compass Rose.  If not, see <http://www.gnu.org/licenses/>.

 */

#define RED_OUT 11
#define GREEN_OUT 10
#define BLUE_OUT 9
#define LED_PIN 2
// #define CHS_DEBUG

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h>

#include "color.h"
// Our Sensor
Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(12345);

// Degree resolution of the Rose.
int ColorDegrees;
#ifdef CHS_DEBUG
// From Adafruit driver
void displaySensorDetails(void)
{
  sensor_t sensor;
  mag.getSensor(&sensor);
  Serial.println("------------------------------------");
  Serial.print  ("Sensor:       "); Serial.println(sensor.name);
  Serial.print  ("Driver Ver:   "); Serial.println(sensor.version);
  Serial.print  ("Unique ID:    "); Serial.println(sensor.sensor_id);
  Serial.print  ("Max Value:    "); Serial.print(sensor.max_value); Serial.println(" uT");
  Serial.print  ("Min Value:    "); Serial.print(sensor.min_value); Serial.println(" uT");
  Serial.print  ("Resolution:   "); Serial.print(sensor.resolution); Serial.println(" uT");  
  Serial.println("------------------------------------");
  Serial.println("");
  delay(500);
}
#endif

// Turn the LED off
void blink_off()
{
   analogWrite(RED_OUT,255);
   analogWrite(GREEN_OUT,255);
   analogWrite(BLUE_OUT,255);
}
// Display a color
void blink_color( color *thecolor)
{
#ifdef CHS_DEBUG
  digitalWrite(LED_PIN,HIGH);
#endif
  analogWrite(RED_OUT,thecolor->red_val);
  analogWrite(GREEN_OUT,thecolor->green_val);
  analogWrite(BLUE_OUT,thecolor->blue_val);
#ifdef CHS_DEBUG
  delay(500);
  // blink_off();
  digitalWrite(LED_PIN,LOW);
  delay(500);
#endif
  return;
}


void setup() {
   pinMode(LED_PIN,OUTPUT);
#ifdef CHS_DEBUG
   Serial.begin(9600);
   digitalWrite(LED_PIN,HIGH);
   delay(1000);
   digitalWrite(LED_PIN,LOW);
#endif
   

   if(! mag.begin()) {
      while(1) 
         digitalWrite(LED_PIN,HIGH);
	 delay(250);
	 digitalWrite(LED_PIN,LOW);
   }
   ColorDegrees=360 / ColorSize;
#ifdef CHS_DEBUG
   displaySensorDetails();
#endif
}

void loop() {
   sensors_event_t event;
   mag.getEvent(&event);
   float heading = atan2(event.magnetic.y,event.magnetic.x);
   if(heading < 0)
     heading += 2*PI;
   if(heading > 2*PI)
      heading -= 2*PI;
   float headingDegrees = heading * 180/M_PI;
#ifdef CHS_DEBUG
   Serial.print("Heading (degrees): ");
   Serial.println(headingDegrees);
   delay(500);
#endif

int colorNum = headingDegrees / ColorDegrees;
#ifdef CHS_DEBUG
Serial.print("colorNum: ");
Serial.println(colorNum);
#endif
blink_color(&Colors[colorNum]);
/*    
  // put your main code here, to run repeatedly:
    blink_color(&Colors[Colorctr]);
    ++Colorctr;
    if (Colorctr > ColorSize) 
      Colorctr = 0;
*/
}
