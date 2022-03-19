// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Commands/RunShooterAutoCommand.h"

#include "Robot.h"

RunShooterAutoCommand::RunShooterAutoCommand() {
  AddRequirements(&Robot::shooter);
}

// Called when the command is initially scheduled.
void RunShooterAutoCommand::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void RunShooterAutoCommand::Execute() {
  Robot::shooter.RunShooterVelocity(SHOOTERVELOCITY);
}

// Called once the command ends or is interrupted.
void RunShooterAutoCommand::End(bool interrupted) {}

// Returns true when the command should end.
bool RunShooterAutoCommand::IsFinished() {
  return false;
}
