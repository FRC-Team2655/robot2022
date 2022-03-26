/**
 * @file Input.cpp
 * @date 1/15/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Handles the source code for the input class.
**/

#include "Input.h"
#include "Robot.h"

/** The constructor for the input class */
Input::Input() {

  /** Assigning the joystick instance to its port number */
  joystick = new frc::Joystick(0);

  /** Assigning all the buttons their values */
  squareBtn = new frc2::JoystickButton(joystick, 1);
  xBtn = new frc2::JoystickButton(joystick, 2);
  circleBtn = new frc2::JoystickButton(joystick, 3);
  triangleBtn = new frc2::JoystickButton(joystick, 4);
  l1Btn = new frc2::JoystickButton(joystick, 5);
  r1Btn = new frc2::JoystickButton(joystick, 6);
  shareBtn = new frc2::JoystickButton(joystick, 9);
  optionsBtn = new frc2::JoystickButton(joystick, 10);
  rightStickBtn = new frc2::JoystickButton(joystick, 12);
  leftStickBtn = new frc2::JoystickButton(joystick, 11);
  dPadDown = new frc2::POVButton(joystick, 180);
  dPadUp = new frc2::POVButton(joystick, 0);
  dPadLeft = new frc2::POVButton(joystick, 270);
  dPadRight = new frc2::POVButton(joystick, 90);


  /** When the circle button is pressed, move the intake in */
  circleBtn->WhenPressed(intakeIn);
  /** When the x button is pressed, move the intake out and run the belts */
  xBtn->WhenPressed(frc2::SequentialCommandGroup(intakeOut, runBelts), true);
  /** When the square button is held, run the shooter at the "dripout" speed. */
  squareBtn->WhenHeld(frc2::ParallelCommandGroup(runShooterDripoutSpeed, runAllBelts));
  /** When the L1 button is held, run the shooter at the shooter velocity */
  l1Btn->WhenHeld(runShooterVelocity);
  /** When the right stick button is held, run all the belts without belt logic */
  rightStickBtn->WhenHeld(runAllBelts);
  /** When the R1 button is held, run the intake rollers. */
  r1Btn->WhenHeld(runIntakeRollers);
  /** When the share button is held, move the climber down without PID */
  shareBtn->WhenHeld(moveClimberDown);
  /** When the options button is pressed, move the climber up without PID */
  optionsBtn->WhileHeld(moveClimberUp);

  triangleBtn->WhenHeld(reverseBelts);

  dPadUp->WhileHeld(runLeftClimberUp);
  dPadLeft->WhileHeld(runLeftClimberDown);
  dPadDown->WhenHeld(runRightClimberDown);
  dPadRight->WhenHeld(runRightClimberUp);
}