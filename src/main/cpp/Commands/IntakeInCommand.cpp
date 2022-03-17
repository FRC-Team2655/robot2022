/**
 * @file IntakeInCommand.cpp
 * @date 3/1/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Source code dealing with pulling the intake in.
**/

#include "Commands/IntakeInCommand.h"
#include "Robot.h"

/** Constructor for the IntakeInCommand class */
IntakeInCommand::IntakeInCommand() {
  // Require the intake for this command
  AddRequirements(&Robot::intake);
}

/** @brief Called when the command is initially scheduled. 
 * @return void
*/
void IntakeInCommand::Initialize() {
  // Run the command to move the intake in
  Robot::intake.IntakeIn();
}

/** @brief Called repeatedly when this Command is scheduled to run 
 * @return void
*/
void IntakeInCommand::Execute() {}

/** @brief Called once the command ends or is interrupted. 
 * @return void
*/
void IntakeInCommand::End(bool interrupted) {}

/** @brief Returns true when the command should end. 
 * @return Whether the command should finish.
*/
bool IntakeInCommand::IsFinished() {
  // End the command after the first run
  return true;
}
