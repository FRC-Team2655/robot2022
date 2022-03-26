// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Commands/ReverseBeltsCommand.h"

#include "Robot.h"

ReverseBeltsCommand::ReverseBeltsCommand() {
  AddRequirements(&Robot::belts);
}

// Called when the command is initially scheduled.
void ReverseBeltsCommand::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void ReverseBeltsCommand::Execute() {
  Robot::belts.RunBeltsReverse();
}

// Called once the command ends or is interrupted.
void ReverseBeltsCommand::End(bool interrupted) {
  Robot::belts.StopBelts();
}

// Returns true when the command should end.
bool ReverseBeltsCommand::IsFinished() {
  return false;
}
