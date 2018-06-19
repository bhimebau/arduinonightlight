// Now we'll control the robot with joysticks.

#include <Servo.h>

// 'define' lets us give nicknames to useful values. Here, we're naming each of the pins we'll use for the joystick inputs.
#define UD1pin 5
#define LR1pin 4
#define B1pin 3
#define UD2pin 2
#define LR2pin 1
#define B2pin 0

Servo middle;
Servo left;
Servo right;
Servo claw;

static boolean PAUSE_FLAG = false;

int INCREMENT = 2;
int minM = 0, maxM=180;
int minL = 0, maxL = 180;
int minR = 0, maxR = 180;
int minC = 0, maxC = 78;

// We'll read measurements from the joysticks, and we'll store them in these variables.
// UD = up/down. LR = left/right

int UD1=0, LR1=0, But1=0, UD2=0, LR2=0, But2=0;

int default_M = 125, default_L = 90, default_R=90, default_C = 35;
static int angle_M=default_M, angle_L=default_L, angle_R=default_R, angle_C=default_C;

char outputString[50];


void setup() {

  middle.attach(11);
  left.attach(10);
  right.attach(9);
  claw.attach(6);

  Serial.begin(9600);
  Serial.println("READY");
}


void loop() {
  
  if (Serial.available()){
  char cmd = Serial.read();

  // We can use the keyboard to pause or reset.
  switch (cmd){
    case 'r':
      left.write(default_L);
      middle.write(default_M);
      right.write(default_R);
      claw.write(default_C);
      break;
    case 'p':
      PAUSE_FLAG = !PAUSE_FLAG;
      break;
  }
  }

// If the program ISN'T paused...

  if (!PAUSE_FLAG){
    // readJoystick will get a number that tells us the position of each joystick. readJoystick is another function you can see below the loop function.
    //
  UD1 = round((readJoystick(UD1pin)*5));
  LR1 = round((readJoystick(LR1pin)*5));
  But1 = abs(round(readJoystick(B1pin)));

  UD2 = -1*round((readJoystick(UD2pin)*5));
  LR2 = -1*(readJoystick(LR2pin)*10);
  But2 = abs(round(readJoystick(B2pin)));

  angle_L += UD1;    
  angle_M += LR1;
  angle_R += UD2;
  angle_C += LR2;

  left.write(angle_L);
  middle.write(angle_M);
  right.write(angle_R);
  claw.write(angle_C);
//
//  if (But2){
//    claw.write(maxC);
//  }
//  else {
//    claw.write(angle_C);
//  }

  sprintf(outputString, "%03d \t %03d \t %03d \t %03d \t %03d \t %03d", UD1, LR1, But1, UD2, LR2, But2);
  Serial.println(outputString);
  }
}

float readJoystick(int Apin){
  // analogRead reads a measurement from the joystick and returns a number from 0-1023. We do some math to change the number to something between -1 and 1.
  float cmd = float(analogRead(Apin)-512.0)/512.0;
  return cmd;
  }
