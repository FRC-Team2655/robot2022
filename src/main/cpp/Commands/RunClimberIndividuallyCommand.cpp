// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Commands/RunClimberIndividuallyCommand.h"

#include "Robot.h"

RunClimberIndividuallyCommand::RunClimberIndividuallyCommand(bool isLeftSide, double upwardSpeed) : isLeftSide(isLeftSide), upwardSpeed(upwardSpeed) {
  AddRequirements(&Robot::climber);
}

// Called when the command is initially scheduled.
void RunClimberIndividuallyCommand::Initialize() {
  Robot::climber.SetClimberCoastMode();
}

// Called repeatedly when this Command is scheduled to run
void RunClimberIndividuallyCommand::Execute() {
  Robot::climber.RunClimberIndividually(isLeftSide, upwardSpeed);
}

// Called once the command ends or is interrupted.
void RunClimberIndividuallyCommand::End(bool interrupted) {
  Robot::climber.StopClimber();

  Robot::climber.SetClimberBrakeMode();
}

// Returns true when the command should end.
bool RunClimberIndividuallyCommand::IsFinished() {
  return false;
}
