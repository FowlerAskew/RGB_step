#include <SoftPWM.h>  //include the SoftPWM library
#include <SoftPWM_timer.h>
int pulseVal = 0;  //this variable stores the value from the reciever
const int input = 8;  //pin input number
const int pin_R = 5;  //pin outputs
const int pin_G = 6;
const int pin_B = 7;
int off_min = 900;  //min setting for all LEDs off
int off_max = 1075;  //max setting for all LEDs off
int first_min = off_max;  //mins and maxes for the first step
int first_max = 1325;
int second_min = first_max;  //min of the second step is the max of the first step
int second_max = 1500;  //second step max
int third_min = second_max;  //same as the other steps
int third_max = 1675;
int fourth_min = third_max;
int fourth_max = 1925;
int fifth_min = fourth_max; 
int fifth_max = 2100;

void setup()
{
  pinMode(input, INPUT);  //declare inputs and outputs
  SoftPWMBegin();
  SoftPWMSet(Pin_R, 0);
  SoftPWMSet(Pin_G, 0);
  SoftPWMSet(Pin_B, 0);
  SoftPWMSetFadeTime(Pin_R, 200, 200);
  SoftPWMSetFadeTime(Pin_G, 200, 200);
  SoftPWMSetFadeTime(Pin_B, 200, 200);
}

void loop()
{
  pulseVal = pulseIn(input, HIGH);  //read the pulsewidth of the input 
  if(pulseVal == off_min && pulseVal <= off_max)  //if the pulsewidth is within the boundaries of the off step...
  {
    SoftPWMSet(pin_R, 0);  //set these values for the colors
    SoftPWMSet(pin_G, 0);  //Choose values from 0 to 255
    SoftPWMSet(pin_B, 0);
  }
  if(pulseVal > first_min && pulseVal <= first_max)  //if the pulsewidth is within the boundaries of the first step...
  {
    SoftPWMSet(pin_R, 87);  //set these values for the colors
    SoftPWMSet(pin_G, 107);  //Choose values from 0 to 255
    SoftPWMSet(pin_B, 127);
  }
  if(pulseVal > second_min && pulseVal <= second_max)  //same as the first block
  {
    SoftPWMSet(pin_R, 89);
    SoftPWMSet(pin_G, 74);
    SoftPWMSet(pin_B, 111);
  }
  if(pulseVal > third_min && pulseVal <= third_max)
  {
    SoftPWMSet(pin_R, 97);
    SoftPWMSet(pin_G, 105);
    SoftPWMSet(pin_B, 87);
  }
  if(pulseVal > fourth_min && pulseVal <= fourth_max)
  {
    SoftPWMSet(pin_R, 96);
    SoftPWMSet(pin_G, 82);
    SoftPWMSet(pin_B, 84);
  }
  if(pulseVal > fifth_min && pulseVal == fifth_max)
  {
    SoftPWMSet(pin_R, 255);
    SoftPWMSet(pin_G, 255);
    SoftPWMSet(pin_B, 255);
  }
}
