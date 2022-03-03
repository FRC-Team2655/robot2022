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

/** Called when the command is initially scheduled. */
void IntakeOutCommand::Initialize() {
  // Move the intake out
  Robot::intake.IntakeOut();
  // Set the variable to track whether the intake is in to false
  Robot::intake.isIntakeIn = false;
}

/** Called repeatedly when this Command is scheduled to run */
void IntakeOutCommand::Execute() {}

/** Called once the command ends or is interrupted. */
void IntakeOutCommand::End(bool interrupted) {}

/** Returns true when the command should end. */
bool IntakeOutCommand::IsFinished() {
  // Return true to run the command once
  return true;
}
