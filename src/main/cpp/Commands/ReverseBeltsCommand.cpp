/**
 * @file ReverseBeltsCommand.cpp
 * @date 3/18/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Source code dealing with running the belts in the reverse direction (backwards).
**/

#include "Commands/ReverseBeltsCommand.h"

#include "Robot.h"

/** Constructor for the ReverseBeltsCommand class */
ReverseBeltsCommand::ReverseBeltsCommand() {
  // This command requires the belts subsystem
  AddRequirements(&Robot::belts);
}

/** @brief Called when the command is initially scheduled.
 * @return void
 */ 
void ReverseBeltsCommand::Initialize() {}

/** @brief Called repeatedly when this Command is scheduled to run
 * @return void
 */ 
void ReverseBeltsCommand::Execute() {
  Robot::belts.RunBeltsReverse();
}

/** @brief Called once the command ends or is interrupted.
 * @return void
 */ 
void ReverseBeltsCommand::End(bool interrupted) {
  Robot::belts.StopBelts();
}

/** @brief Returns true when the command should end.
 * @return Whether the command is finished
 */ 
bool ReverseBeltsCommand::IsFinished() {
  return false;
}
