// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Commands/RunShooterAutoCommand.h"

#include "Robot.h"

/** Constructor of the RunShooterAutoCommand class */
RunShooterAutoCommand::RunShooterAutoCommand() {
  AddRequirements(&Robot::shooter);
}

/** @brief Called when the command is initially scheduled.
 * @return void
 */ 
void RunShooterAutoCommand::Initialize() {}

/** @brief Called repeatedly when this Command is scheduled to run
 * @return void
 */ 
void RunShooterAutoCommand::Execute() {
  Robot::shooter.RunShooterVelocity(SHOOTERVELOCITY);
}

/** @brief Called once the command ends or is interrupted.
 * @return void
 */ 
void RunShooterAutoCommand::End(bool interrupted) {}

/** @brief Returns true when the command should end.
 * @return Whether the command should finish
 */ 
bool RunShooterAutoCommand::IsFinished() {
  return false;
}
