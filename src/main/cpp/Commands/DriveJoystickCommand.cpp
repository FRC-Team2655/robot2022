// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Commands/DriveJoystickCommand.h"

#include "Robot.h"

DriveJoystickCommand::DriveJoystickCommand() {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(&Robot::driveBase);
}

// Called when the command is initially scheduled.
void DriveJoystickCommand::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void DriveJoystickCommand::Execute() {
  double rawForward = (Robot::input.joystick.GetRawAxis(3) + 1) / 2;
  double rawBackward = (Robot::input.joystick.GetRawAxis(4) + 1) / 2;
  double deadband = 0.1;
  double driveDirection;

  if (rawForward > deadband && rawBackward > deadband) driveDirection = 0;
  else if (rawForward > deadband) driveDirection = rawForward;
  else if (rawBackward > deadband) driveDirection = -rawBackward;


  //double rotate = -0.5 * jshelper::getAxisValue(Robot::input.rotateAxisConfig, Robot::input.joystick.GetRawAxis(0));
  //double power = jshelper::getAxisValue(Robot::input.driveAxisConfig, driveDirection);

	//Robot::driveBase.arcadeDrive(power, rotate);
}

// Called once the command ends or is interrupted.
void DriveJoystickCommand::End(bool interrupted) {}

// Returns true when the command should end.
bool DriveJoystickCommand::IsFinished() {
  return false;
}
