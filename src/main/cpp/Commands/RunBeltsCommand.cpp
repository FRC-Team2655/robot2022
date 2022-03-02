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
  AddRequirements(&Robot::belts);
}

/** Called when the command is initially scheduled. */
void RunBeltsCommand::Initialize() {}

/** Called repeatedly when this Command is scheduled to run */
void RunBeltsCommand::Execute() {
  // Run the belts using belt logic.
  Robot::belts.RunBelts();
}

/** Called once the command ends or is interrupted. */
void RunBeltsCommand::End(bool interrupted) {
  // Stop all the belts.
  Robot::belts.StopAllBelts();
}

/** Returns true when the command should end. */
bool RunBeltsCommand::IsFinished() {
  return false;
}
