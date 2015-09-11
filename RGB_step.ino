/********************************************
Code for LED Step Controller by Fowler Askew.
Written with Pin Numbers for ATtiny 44/84.
Use this code however you like.

Uses code from jamesotron rgb_spectrum.c
https://gist.github.com/jamesotron

------------ MODE SELECT CODES: -------------
Each switch = 1 if on, 0 if off.
Sum of switches selects modes
0 = Radio Control
1 = mode 1, 2 = mode 2, etc.
*********************************************/

int pulseVal = 0;  //this variable stores the value from the reciever
int modeVal = 0; //this variable selects the mode of the controller. 0 = RC, >1 = preprogrammed mode
const int input = 9;  //pin input number
const int Pin_R = 8;  //pin outputs
const int Pin_G = 7;
const int Pin_B = 6;
int modeSelect[6];  //define an array to hold the values from mode selection switches

void setup()
{
  pinMode(input, INPUT);  //declare inputs and outputs. We only need to define inputs
  for(int x = 0; x < 6; x++){
    pinMode(x, INPUT);
  }
  for(int y = 0; y < 6; y++){
    modeSelect[y] = digitalRead(y);
  }
  for(int z = 0; z < 6; z++){
    modeVal = modeVal +modeSelect[z];
  }
  analogWrite(Pin_R, 0);
  analogWrite(Pin_G, 0);
  analogWrite(Pin_B, 0);
}

void loop()
{
  if (modeVal == 0){ RC(); }
  else if (modeVal == 1){ mode1(); }
  else if (modeVal == 2){ mode2(); }
  else if (modeVal == 3){ mode3(); }
  else if (modeVal == 4){ mode4(); }
  else if (modeVal == 5){ mode5(); }
  else if (modeVal == 6){ mode6(); }
}

void setColorRGB(unsigned int red, unsigned int green, unsigned int blue) {  //sets colors
  analogWrite(Pin_R, red);
  analogWrite(Pin_G, green);
  analogWrite(Pin_B, blue);
 }

void RC()
{
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

  pulseVal = pulseIn(input, HIGH);  //read the pulsewidth of the input 
  if(pulseVal == off_min && pulseVal <= off_max)  //if the pulsewidth is within the boundaries of the off step...
  {
    setColorRGB(0, 0, 0);  //sets a value of 0 for each color
  }
  if(pulseVal > first_min && pulseVal <= first_max)  //if the pulsewidth is within the boundaries of the first step...
  {
    setColorRGB(87, 107, 127);  //set red leds to 87, green to 107, and blue to 127
  }
  if(pulseVal > second_min && pulseVal <= second_max)  //same as the first block
  {
    setColorRGB(89, 74, 111);
  }
  if(pulseVal > third_min && pulseVal <= third_max)
  {
    setColorRGB(97, 105, 87);
  }
  if(pulseVal > fourth_min && pulseVal <= fourth_max)
  {
    setColorRGB(96, 40, 80);
  }
  if(pulseVal > fifth_min && pulseVal == fifth_max)
  {
    setColorRGB(255, 255, 255);
  }
}

void mode1()  //rainbow spectrum cycle
{
  // Start off with the LED off.
  setColorRGB(0,0,0);

while(1 == 1) {
  unsigned int rgbColor[3];

  // Start off with red.
  rgbColor[0] = 255;
  rgbColor[1] = 0;
  rgbColor[2] = 0;  

  // Choose the colors to increment and decrement.
  for (int decColor = 0; decColor < 3; decColor += 1) {
    int incColor = decColor == 2 ? 0 : decColor + 1;

    // cross-fade the two colors.
    for(int i = 0; i < 255; i += 1) {
      rgbColor[decColor] -= 1;
      rgbColor[incColor] += 1;
      
      setColorRGB(rgbColor[0], rgbColor[1], rgbColor[2]);
      delay(5);
    }
  }
}
}

void mode2()
{
  
}

void mode3()
{
  
}

void mode4()
{
  
}

void mode5()
{
  
}

void mode6()
{
  
}
