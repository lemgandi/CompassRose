#define RED_OUT 11
#define GREEN_OUT 10
#define BLUE_OUT 9
#define LED_PIN 2

#include "color.h"
int Colorctr;

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
  digitalWrite(LED_PIN,HIGH);
  analogWrite(RED_OUT,thecolor->red_val);
  analogWrite(GREEN_OUT,thecolor->green_val);
  analogWrite(BLUE_OUT,thecolor->blue_val);
  delay(500);
  // blink_off();
  digitalWrite(LED_PIN,LOW);
  delay(500);
  return;
}


void setup() {
   Serial.begin(9600);
   pinMode(LED_PIN,OUTPUT);
   digitalWrite(LED_PIN,HIGH);
   delay(1000);
   digitalWrite(LED_PIN,LOW);
   Colorctr = 0;
   Serial.print("Color array size:");
   Serial.println(Color_size);
}

void loop() {

    
  // put your main code here, to run repeatedly:
    blink_color(&Colors[Colorctr]);
    ++Colorctr;
    if (Colorctr > Color_size) 
      Colorctr = 0;
}
