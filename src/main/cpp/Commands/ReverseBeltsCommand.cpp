/**
 * @file ReverseBeltsCommand.cpp
 * @date 4/4/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Source code dealing with running the belts in the inverse direction.
**/

#include "Commands/ReverseBeltsCommand.h"

#include "Robot.h"

/** Constructor for the ReserseBeltsCommand class */
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
  // Run the belts in the reverse direction
  Robot::belts.RunBeltsReverse();
  Robot::intake.RunIntakeRollers(-0.5);
}

/** @brief Called once the command ends or is interrupted.
 * @return void
 */ 
void ReverseBeltsCommand::End(bool interrupted) {
  // Stop the belts from running
  Robot::belts.StopBelts();
  Robot::intake.RunIntakeRollers(0);
}

/** @brief Returns true when the command should end.
 * @return Whether the command should finish
 */
bool ReverseBeltsCommand::IsFinished() {
  return false;
}
