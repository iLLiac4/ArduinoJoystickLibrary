// Analog eBrake-Handbrake 
// PIN A0 to 10k pot output or. Hall sensor analog reading (KY-035; KY-024) - Throttle Axis
// Use with Arduino ProMicro, LillyPad,...
// This is modified version with just one active axis to avoid conflicts in game.


#include <Joystick.h>

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_GAMEPAD,
  0, 0,                        // Button Count, Hat Switch Count
  false, false, false,    // X, Y, Z 
  false, false, false,    // Rx, Ry, Rz
  false, false,              // rudder, throttle
  false, true, false);   // accelerator, brake, steering

void setup()

{
  pinMode(A0, INPUT); 
  Joystick.begin();
}

const int pinToButtonMap = A0;

void loop()

{
  int pot = analogRead(A0);
  int mapped = map(pot,0,1023,0,255);
  Joystick.setBrake(mapped);
}
