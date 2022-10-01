// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Commands/ShootOneBallCommand.h"

#include "Robot.h"
#include "RobotMap.h"

ShootOneBallCommand::ShootOneBallCommand() {
  AddRequirements(&Robot::belts);
}

// Called when the command is initially scheduled.
void ShootOneBallCommand::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void ShootOneBallCommand::Execute() {
  Robot::belts.RunAllBelts();
  Robot::shooter.RunShooterVelocity(SHOOTERVELOCITY);
  Robot::shooter.RunShooterKicker(SHOOTERKICKERSPEED);
}

// Called once the command ends or is interrupted.
void ShootOneBallCommand::End(bool interrupted) {
  Robot::belts.StopBelts();
}

// Returns true when the command should end.
bool ShootOneBallCommand::IsFinished() {
  return !Robot::belts.proximSensor.Get();
}
