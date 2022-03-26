/**
 * @file RunShooterAutoCommand.cpp
 * @date 3/2/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Source code dealing with running the shooter and not stopping it once the command ends.
**/

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
  return Robot::shooter.isShooterAtMax;
}
