
const int analogInPin0 = A0; //joystick 
const int analogInPin1 = A1; //joystick
//---------pan stepper-----------------
const int XstepperPulse = 2;
const int XstepperDirection = 3;
const int XstepperEnable = 4;
//--------tilt stepper-----------------
const int YstepperPulse = 5;
const int YstepperDirection = 6;
const int YstepperEnable = 7;


int StepDelay1 = 3;// 0 is fastest
int StepDelay2 =1;// 1 is fastest
int sensorValue0 = 0; //joystick
int sensorValue1 = 0; //joystick
int Xhome=500;
int Yhome=500;


void setup() {

pinMode(XstepperPulse, OUTPUT);
pinMode(XstepperDirection, OUTPUT);
pinMode(XstepperEnable, OUTPUT);

pinMode(YstepperPulse, OUTPUT);
pinMode(YstepperDirection, OUTPUT);
pinMode(YstepperEnable, OUTPUT);

sensorValue0 = analogRead(analogInPin0);// joystick
sensorValue1 = analogRead(analogInPin1);// joystick

//sets pan and tilt home to joystick center
Xhome=sensorValue0;
Yhome=sensorValue1;

digitalWrite (YstepperEnable, LOW);

}

void loop() {
  // read the joystick
sensorValue0 = analogRead(analogInPin0);// joystick
sensorValue1 = analogRead(analogInPin1);// joystick
  
//--------------pan---------------------------------
if (sensorValue1 > (Yhome+10))
{
digitalWrite (YstepperDirection, LOW);
digitalWrite (YstepperPulse, HIGH);
delay (StepDelay1);
digitalWrite (YstepperPulse, LOW);
delay (StepDelay2);
Yhome ++;
}


if (sensorValue1 < (Yhome-10))
{
digitalWrite (YstepperDirection, HIGH);
digitalWrite (YstepperPulse, HIGH);
delay (StepDelay1);
digitalWrite (YstepperPulse, LOW);
delay (StepDelay2);
Yhome --;
}
//-----------------tilt---------------------------------


if (sensorValue0 > (Xhome+10))
{
digitalWrite (XstepperDirection, LOW);
digitalWrite (XstepperPulse, HIGH);
delay (StepDelay1);
digitalWrite (XstepperPulse, LOW);
delay (StepDelay2);
Xhome ++;
}


if (sensorValue0 < (Xhome-10))
{
digitalWrite (XstepperDirection, HIGH);
digitalWrite (XstepperPulse, HIGH);
delay (StepDelay1);
digitalWrite (XstepperPulse, LOW);
delay (StepDelay2);
Xhome --;
}
}
