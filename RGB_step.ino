int pulseVal = 0;  //this variable stores the value from the reciever
const int input = 8;  //pin input number
const int pin_R = 5;  //pin outputs
const int pin_G = 6;
const int pin_B = 7;
int first_min = 0;  //mins and maxes for the first step
int first_max = 0;
int second_min = first_max;  //min of the second step is the max of the first step
int second_max = 0;  //second step min
int third_min = second_max;  //same as the other steps
int third_max = 0;
int fourth_min = third_max;
int fourth_max = 0;
int fifth_min = fourth_max; 
int fifth_max = 0;
int sixth_min = fifth_max;
int sixth_max = 0;

void setup()
{
  pinMode(input, INPUT);  //declare inputs and outputs
  pinMode(pin_R, OUTPUT);
  pinMode(pin_G, OUTPUT);
  pinMode(pin_B, OUTPUT);
}

void loop()
{
  pulseVal = pulseIn(input, HIGH);  //read the pulsewidth of the input
  if(pulseVal >= first_min && pulseVal <= first_max)  //if the pulsewidth is within the boundaries of the first step..
  {
    analogWrite(pin_R, 87);  //set these values for the colors
    analogWrite(pin_G, 107);  //Choose values from 0 to 255
    analogWrite(pin_B, 127);
  }
  if(pulseVal > second_min && pulseVal <= second_max)  //same as the first block
  {
    analogWrite(pin_R, 89);
    analogWrite(pin_G, 74);
    analogWrite(pin_B, 111);
  }
  if(pulseVal > third_min && pulseVal <= third_max)
  {
    analogWrite(pin_R, 97);
    analogWrite(pin_G, 105);
    analogWrite(pin_B, 87);
  }
  if(pulseVal > fourth_min && pulseVal <= fourth_max)
  {
    analogWrite(pin_R, 96);
    analogWrite(pin_G, 82);
    analogWrite(pin_B, 84);
  }
  if(pulseVal > fifth_min && pulseVal <= fifth_max)
  {
    analogWrite(pin_R, 33);
    analogWrite(pin_G, 78);
    analogWrite(pin_B, 71);
  }
  if(pulseVal > sixth_min && pulseVal <= sixth_max)
  {
    analogWrite(pin_R, 86);
    analogWrite(pin_G, 82);
    analogWrite(pin_B, 91);
  }
}
