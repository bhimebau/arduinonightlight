#include <Servo.h>

Servo middle;
Servo left;
Servo right;
Servo claw;

// This is a boolean variable (true or false) that we'll use to keep track if our program is paused.
static boolean PAUSE_FLAG = true;

void setup() {

  middle.attach(11);
  left.attach(10);
  right.attach(9);
  claw.attach(6);


  // Serial communication lets us send commands to the arduino. 
  // 9600 refers to the speed we're transmitting data.
  
  Serial.begin(9600);

  // Open up the Serial monitor under tools. We'll be able to send commands by typing here.
  Serial.println("Ready. Hit ENTER key to start.");

  while(!Serial.available()){
  }
  
  Serial.println("Use ENTER key to pause/resume.");
}

void loop() {
  
  checkPause();

// The robot only moves if the program is not paused, PAUSE_FLAG = false. ! means NOT.
  if (!PAUSE_FLAG){
    middle.write(125);
    left.write(90);
    right.write(120);
    claw.write(120);
  }
  
  delay(1000);

  checkPause();

  if (!PAUSE_FLAG){
    middle.write(125);
    left.write(60);
    right.write(60);
    claw.write(0);
  } 
  
  delay(1000);
}


// This function checks if we've written anything to the serial monitor. 
// Anything we type will pause or unpause the robot when we press ENTER.

void checkPause(){
  if (Serial.available()){
    Serial.read();
    PAUSE_FLAG = !PAUSE_FLAG;
  }
}


