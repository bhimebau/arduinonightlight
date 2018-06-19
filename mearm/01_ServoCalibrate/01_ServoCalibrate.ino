// In this code, we'll be calibrating each of the servos according to the MeArm instructions.
// We'll use a special library, Servo.h, which gives us some useful tools for servo control.

#include <Servo.h>

// Here we create some servo motor objects, one for each motor on the MeArm.
Servo middle;
Servo left;
Servo right;
Servo claw;

void setup() {

  // Each motor will be connected to a PWM pin (one marked with a ~) on the Arduino board.
  // Here we tell the arduino which motor is attached to which pin.
  middle.attach(11);
  left.attach(10);
  right.attach(9);
  claw.attach(6);

}


void loop() {

  // We write an angle to each Servo motor.
  middle.write(90);
  left.write(90);
  right.write(90);
  claw.write(35);

  delay(500);
}
