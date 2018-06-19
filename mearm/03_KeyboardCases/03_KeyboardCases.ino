// In this program, we'll move the robot using the keyboard.

#include <Servo.h>

Servo middle;
Servo left;
Servo right;
Servo claw;

// We'll set some variables for the range of motion of each motor. You'll change these values after some testing.
int INCREMENT = 2;
int minM = 0, maxM=180;
int minL = 0, maxL = 180;
int minR = 0, maxR = 180;
int minC = 0, maxC = 78;

// This is how we'll store some text that we'll display in the serial monitor. We'll display the angles of each motor.
char outputString[50];

// We set some initial angles for the motors, but we'll be changing them.
static int angle_M=125, angle_L=90, angle_R=90, angle_C=35;

void setup() {

  middle.attach(11);
  left.attach(10);
  right.attach(9);
  claw.attach(6);

  // Serial communication is a way that data is transmitted between the computer and the arduino.
  Serial.begin(9600);
  Serial.println("Ready. Hit ENTER key to start.");

  while(!Serial.available()){
  }

  Serial.read();
}


void loop() {

  // We loop until there's a keyboard entry.
  if (Serial.available()){
  char cmd = Serial.read();

  // We save the keyboard entry as cmd. And assign each letter an outcome.
  // We will use the keys A, S, D, W and J, K, L, I
  // angle -= 5 is the same as angle = angle - 5.

  switch (cmd){
    case 'a':
      angle_M -= INCREMENT;
      break;
    case 'd':
      angle_M += INCREMENT; 
      break;
    case 's':
      angle_L -= INCREMENT;
      break;
    case 'w':
      angle_L += INCREMENT;
      break;
    case 'j':
      angle_R -= INCREMENT;
      break;
    case 'l':
      angle_R += INCREMENT;
      break;
    case 'k':
      angle_C -= INCREMENT;
      break;
    case 'i':
      angle_C += INCREMENT;
      break;
  }

  // Max returns the bigger of two numbers.
  // Min returns the smaller of two numbers.
  // If we increase past the maximum angle, the motor will stop at the max angle. Same with going below the min.
  angle_M = max(min(angle_M, maxM), minM);
  angle_L = max(min(angle_L, maxL), minL);
  angle_R = max(min(angle_R, maxR), minR);
  angle_C = max(min(angle_C, maxC), minC);

  middle.write(angle_M);
  left.write(angle_L);
  right.write(angle_R);
  claw.write(angle_C);

  // And we write the motor angles to serial. We'll read them off in the serial monitor.
  sprintf(outputString, "Middle: %03d, Left: %03d, Right: %03d, Claw: %03d", angle_M, angle_L, angle_R, angle_C);
  Serial.println(outputString);
  }
}
