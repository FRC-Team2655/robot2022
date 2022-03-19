/**
 * @file StopShooterCommand.cpp
 * @date 3/18/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Source code dealing with running stopping the shooter from running.
**/

#include "Commands/StopShooterCommand.h"

#include "Robot.h"

/** Constructor for the stop shooter command class */
StopShooterCommand::StopShooterCommand() {
  // This command requires the shooter
  AddRequirements(&Robot::shooter);
}

/** @brief Called when the command is initially scheduled.
 * @return void
 */ 
void StopShooterCommand::Initialize() {
  Robot::shooter.RunShooterPercentage(0);
}

/** @brief Called repeatedly when this Command is scheduled to run
 * @return void
 */ 
void StopShooterCommand::Execute() {}

/** @brief Called once the command ends or is interrupted.
 * @return void
 */ 
void StopShooterCommand::End(bool interrupted) {}

/** @brief Returns true when the command should end.
 * @return Whether the command should end.
 */ 
bool StopShooterCommand::IsFinished() {
  return true;
}
