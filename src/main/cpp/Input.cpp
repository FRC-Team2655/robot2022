/**
 * @file Input.h
 * @date 1/15/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Handles the source code for the input class.
**/

#include "Input.h"

/** The constructor for the input class */
Input::Input() {
  /** Assigning the joystick instance to its port number */
  joystick = new frc::Joystick(0);
  
  /** Assigning all the buttons their values */
  xBtn = new frc2::JoystickButton(joystick, 2);
  squareBtn = new frc2::JoystickButton(joystick, 1);
  triangleBtn = new frc2::JoystickButton(joystick, 4);
  circleBtn = new frc2::JoystickButton(joystick, 3);
  l2Btn = new frc2::JoystickButton(joystick, 7);
  l1Btn = new frc2::JoystickButton(joystick, 5);
  r2Btn = new frc2::JoystickButton(joystick, 8);
  r1Btn = new frc2::JoystickButton(joystick, 6);
  shareBtn = new frc2::JoystickButton(joystick, 9);
  optionsBtn = new frc2::JoystickButton(joystick, 10);
  rightStickBtn = new frc2::JoystickButton(joystick, 12);
}