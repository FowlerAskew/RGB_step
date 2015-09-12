/********************************************
Code for LED Step Controller by Fowler Askew.
Written with Pin Numbers for ATtiny 44/84.
CURRENTLY HAS PIN NUMBERS FOR ARDUINO UNO
Use this code however you like.

Uses code from jamesotron rgb_spectrum.c
https://gist.github.com/jamesotron

------------ MODE SELECT CODES: -------------
Each switch = 1 if on, 0 if off.
Sum of switches selects modes
0 = Radio Control
1 = mode 1, 2 = mode 2, etc.
*********************************************/

int modeVal = 0; //this variable selects the mode of the controller. 0 = RC, >1 = preprogrammed mode
const int Pin_R = 9;  //output pins
const int Pin_G = 10;
const int Pin_B = 11;
const int input = 8;  //input pins
int modeSelect[6];  //define an array to hold the values from mode selection switches

void setup()
{
  //Serial.begin(9600);
  pinMode(input, INPUT);  //declare inputs and outputs. We only need to define inputs
  //Serial.print("Initialize pin: ");
  for(int x = 2; x < 8; x++){
    pinMode(x, INPUT);
    //Serial.print(x);
    //Serial.print("...");
  }
  //Serial.println();
  //Serial.println();
  //Serial.print("Read pin: ");
  for(int y = 2; y < 8; y++){
    modeSelect[y] = digitalRead(y);
    //Serial.print(y);
    //Serial.print("...");
  }
  //Serial.println();
  //Serial.println();
  //Serial.print("Mode selected: ");
  for(int z = 2; z < 8; z++){
    modeVal = modeVal + modeSelect[z];
  }
  //Serial.println(modeVal);
  setColorRGB(0, 0, 50);
  delay(100);
  setColorRGB(0, 0, 0);
}

void loop()
{
  if (modeVal == 0){while(1 == 1){ RC();}}
  else if (modeVal == 1){while(1 == 1){ mode1();}}
  else if (modeVal == 2){while(1 == 1){ mode2();}}
  else if (modeVal == 3){while(1 == 1){ mode3();}}
  else if (modeVal == 4){while(1 == 1){ mode4();}}
  else if (modeVal == 5){while(1 == 1){ mode5();}}
  else if (modeVal == 6){while(1 == 1){ mode6();}}
  else setColorRGB(0, 0, 0);
}

void setColorRGB(unsigned int red, unsigned int green, unsigned int blue) {  //sets colors
  analogWrite(Pin_R, red);
  analogWrite(Pin_G, green);
  analogWrite(Pin_B, blue);
  //Serial.println("FUNCTION CALLED: setColorRGB");
 }

void RC()
{
  int pulseVal = 0;  //this variable stores the value from the reciever
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

//Serial.println("Reciever Control");
  pulseVal = pulseIn(input, HIGH);  //read the pulsewidth of the input
  //Serial.println(pulseVal);
  if(pulseVal == off_min && pulseVal <= off_max)  //if the pulsewidth is within the boundaries of the off step...
  {
    setColorRGB(0, 0, 0);  //sets a value of 0 for each color
    //Serial.println("Step 1");
  }
  if(pulseVal > first_min && pulseVal <= first_max)  //if the pulsewidth is within the boundaries of the first step...
  {
    setColorRGB(87, 107, 127);  //set red leds to 87, green to 107, and blue to 127
    //Serial.println("Step 2");
  }
  if(pulseVal > second_min && pulseVal <= second_max)  //same as the first block
  {
    setColorRGB(89, 74, 111);
    //Serial.println("Step 3");
  }
  if(pulseVal > third_min && pulseVal <= third_max)
  {
    setColorRGB(97, 105, 87);
    //Serial.println("Step 4");
  }
  if(pulseVal > fourth_min && pulseVal <= fourth_max)
  {
    setColorRGB(96, 40, 80);
    //Serial.println("Step 5");
  }
  if(pulseVal > fifth_min && pulseVal == fifth_max)
  {
    setColorRGB(255, 255, 255);
    //Serial.println("Step 6");
  }
}

void mode1()  //rainbow spectrum cycle
{
  //Serial.println("Mode 1");
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

void mode2()  //random color flashes
{
  //Serial.println("Mode 2");
  const int a = 1000;
  while (1 == 1){
    int ledcolor = random(7);  //randomly selects a number 0 to 6
    switch (ledcolor){
      case 0:  //case for ledcolor equal to 0
      setColorRGB(204, 0, 0);
      delay(a);
      setColorRGB(0, 0, 0);
      break;
      case 2: //case for ledcolor equal to 1
      setColorRGB(0, 0, 255);
      delay(a);
      setColorRGB(0, 0, 0);
      break;
      case 3: //case for ledcolor equal to 0
      setColorRGB(160, 255, 0);
      delay(a);
      setColorRGB(0, 0, 0);
      break;
      case 4: //case for ledcolor equal to 0
      setColorRGB(168, 0, 255);
      delay(a);
      setColorRGB(0, 0, 0);
      break;
      case 5: //case for ledcolor equal to 0
      setColorRGB(0, 255, 255);
      delay(a);
      setColorRGB(0, 0, 0);
      break;
      case 6: //case for ledcolor equal to 0
      setColorRGB(255, 255, 255);
      delay(a);
      setColorRGB(0, 0, 0);
      break;
  }
  }
}

void mode3()
{
  //Serial.println("Mode 3");
  const int a = 2500;
  while (1 == 1){
    int ledcolor = random(7);  //randomly selects a number 0 to 6
    switch (ledcolor){
      case 0:  //case for ledcolor equal to 0
      setColorRGB(204, 0, 0);
      delay(a);
      setColorRGB(0, 0, 0);
      break;
      case 2: //case for ledcolor equal to 1
      setColorRGB(0, 0, 255);
      delay(a);
      setColorRGB(0, 0, 0);
      break;
      case 3: //case for ledcolor equal to 0
      setColorRGB(160, 255, 0);
      delay(a);
      setColorRGB(0, 0, 0);
      break;
      case 4: //case for ledcolor equal to 0
      setColorRGB(168, 0, 255);
      delay(a);
      setColorRGB(0, 0, 0);
      break;
      case 5: //case for ledcolor equal to 0
      setColorRGB(0, 255, 255);
      delay(a);
      setColorRGB(0, 0, 0);
      break;
      case 6: //case for ledcolor equal to 0
      setColorRGB(255, 255, 255);
      delay(a);
      setColorRGB(0, 0, 0);
      break;
  }
  }
}

void mode4()
{
  //Serial.println("Mode 4");
  setColorRGB(255, 0, 0);
}

void mode5()
{
  //Serial.println("Mode 5");
  setColorRGB(0, 255, 0);
}

void mode6()
{
  //Serial.println(Mode 6");
  setColorRGB(0, 0, 255);
}
