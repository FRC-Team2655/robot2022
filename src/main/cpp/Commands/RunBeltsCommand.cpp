// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Commands/RunBeltsCommand.h"

RunBeltsCommand::RunBeltsCommand() {
  AddRequirements(&Robot::belts);
}

// Called when the command is initially scheduled.
void RunBeltsCommand::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void RunBeltsCommand::Execute() {
  Robot::belts.RunBelts();
}

// Called once the command ends or is interrupted.
void RunBeltsCommand::End(bool interrupted) {
  Robot::belts.StopAllBelts();
}

// Returns true when the command should end.
bool RunBeltsCommand::IsFinished() {
  return false;
}
