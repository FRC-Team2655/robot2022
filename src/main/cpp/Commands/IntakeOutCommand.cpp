/**
 * @file IntakeOutCommand.cpp
 * @date 3/1/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Source code dealing with pushing the intake out.
**/

#include "Commands/IntakeOutCommand.h"
#include "Robot.h"

/** Constructor for the IntakeOutCommand class */
IntakeOutCommand::IntakeOutCommand() {
  // Require the intake subsystem for this command
  AddRequirements(&Robot::intake);
}

/** @brief Called when the command is initially scheduled. 
 * @return void
*/
void IntakeOutCommand::Initialize() {
  // Move the intake out
  Robot::intake.IntakeOut();
}

/** @brief Called repeatedly when this Command is scheduled to run 
 * @return void
*/
void IntakeOutCommand::Execute() {
}

/** @brief Called once the command ends or is interrupted. 
 * @return void
*/
void IntakeOutCommand::End(bool interrupted) {}

/** @brief Returns true when the command should end. 
 * @return Whether the command should finish.
*/
bool IntakeOutCommand::IsFinished() {
  // Return true to run the command once
  return true;
}
