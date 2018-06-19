#include <Servo.h>

Servo middle;
Servo left;
Servo right;
Servo claw;

static boolean PAUSE_FLAG = true;

void setup() {

  middle.attach(11);
  left.attach(10);
  right.attach(9);
  claw.attach(6);
}


void loop() {

// Now we're going to loop between two different poses.

  // Pose 1
  middle.write(125);
  left.write(90);
  right.write(120);
  claw.write(120);

  // Delay tells the arduino to pause for a set a duration in milliseconds. 1000 milliseconds = 1 second
  delay(1000);

  // Pose 2
  middle.write(125);
  left.write(60);
  right.write(60);
  claw.write(0);
  
  delay(1000);

  // Add your own poses and delays to make the arm do a dance!
}
