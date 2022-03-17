/**
 * @file RunBeltsCommand.cpp
 * @date 3/1/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Source code dealing with running the belts using belt logic.
**/

#include "Commands/RunBeltsCommand.h"
#include <Robot.h>

/** Constructor for the RunBeltsCommand. */
RunBeltsCommand::RunBeltsCommand() {
  // Require the belts subsystem for this command
  AddRequirements(&Robot::belts);
}

/** @brief Called when the command is initially scheduled. 
 * @return void
*/
void RunBeltsCommand::Initialize() {}

/** @brief Called repeatedly when this Command is scheduled to run 
 * @return void
*/
void RunBeltsCommand::Execute() {
  // Run the belts using belt logic.
  Robot::belts.RunBelts();
}

/** @brief Called once the command ends or is interrupted. 
 * @return void
*/
void RunBeltsCommand::End(bool interrupted) {
  // Stop all the belts.
  Robot::belts.StopBelts();
}

/** @brief Returns true when the command should end. 
 * @return Whether the command should finish.
*/
bool RunBeltsCommand::IsFinished() {
  // Returns true, and the command ends, when the intake is in.
  return Robot::intake.isIntakeIn;
}
