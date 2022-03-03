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

/** Called when the command is initially scheduled. */
void RunAllBeltsCommand::Initialize() {}

/** Called repeatedly when this Command is scheduled to run */
void RunAllBeltsCommand::Execute() {
  // Running all the belts at a fixed percentage without belt logic.
  Robot::belts.RunAllBelts();
}

/** Called once the command ends or is interrupted. */
void RunAllBeltsCommand::End(bool interrupted) {
  // Stop all the belts from running.
  Robot::belts.StopAllBelts();
}

/** Returns true when the command should end. */
bool RunAllBeltsCommand::IsFinished() {
  return false;
}
