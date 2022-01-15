/**
 * @file Robot.cpp
 * @date 1/13/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Source code dealing with driving the robot by joystick control.
**/

#include "Commands/DriveJoystickCommand.h"

#include "Robot.h"

/** The constructor of the DriveJoystickCommand */
DriveJoystickCommand::DriveJoystickCommand() {
  /** This command requires control of the drive base */
  AddRequirements(&Robot::driveBase);
}

/** Called when the command is initially scheduled. */
void DriveJoystickCommand::Initialize() {}

/** Called repeatedly when this Command is scheduled to run */
void DriveJoystickCommand::Execute() {
  /** Scaling the raw joystick trigger inputs */
  double rawForward = (Robot::input.joystick.GetRawAxis(3) + 1) / 2;
  double rawBackward = (Robot::input.joystick.GetRawAxis(4) + 1) / 2;

  /** Defining the deadband */
  double deadband = 0.1;

  /** The direction the robot will be driving in: forward or backward */
  double driveDirection;

  /** If both buttons are pressed, do nothing. */
  if (rawForward > deadband && rawBackward > deadband) driveDirection = 0;
  /** If we are driving forward, set the drive direction to forward */
  else if (rawForward > deadband) driveDirection = rawForward;
  /** If we are driving backward, set the drive direction to backward */
  else if (rawBackward > deadband) driveDirection = -rawBackward;


  //double rotate = -0.5 * jshelper::getAxisValue(Robot::input.rotateAxisConfig, Robot::input.joystick.GetRawAxis(0));
  //double power = jshelper::getAxisValue(Robot::input.driveAxisConfig, driveDirection);

	//Robot::driveBase.arcadeDrive(power, rotate);
}

/** Called once the command ends or is interrupted. */
void DriveJoystickCommand::End(bool interrupted) {}

/** Returns true when the command should end. */
bool DriveJoystickCommand::IsFinished() {
  return false;
}
