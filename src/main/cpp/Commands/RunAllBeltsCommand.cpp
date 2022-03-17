/**
 * @file RunAllBeltsCommand.cpp
 * @date 3/2/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Source code dealing with running all the belts at a fixed percentage without the belt logic.
**/

#include "Commands/RunAllBeltsCommand.h"
#include "Robot.h"

/** The constructor for the RunAllBeltsCommand class */
RunAllBeltsCommand::RunAllBeltsCommand() {
  // Requiring the belts subsystem for this command.
  AddRequirements(&Robot::belts);
}

/** @brief Called when the command is initially scheduled. 
 * @return void
*/
void RunAllBeltsCommand::Initialize() {}

/** @brief Called repeatedly when this Command is scheduled to run 
 * @return void
*/
void RunAllBeltsCommand::Execute() {
  // Running all the belts at a fixed percentage without belt logic.
  Robot::belts.RunAllBelts();
}

/** @brief Called once the command ends or is interrupted. 
 * @return void
*/
void RunAllBeltsCommand::End(bool interrupted) {
  // Stop all the belts from running.
  Robot::belts.StopBelts();
}

/** @brief Returns true when the command should end. 
 * @return Whether the command should finish.
*/
bool RunAllBeltsCommand::IsFinished() {
  return false;
}
