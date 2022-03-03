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

/** Called when the command is initially scheduled. */
void IntakeInCommand::Initialize() {
  // Run the command to move the intake in
  Robot::intake.IntakeIn();
  // Set the variable to track whether the intake is in to true
  Robot::intake.isIntakeIn = true;
}

/** Called repeatedly when this Command is scheduled to run */
void IntakeInCommand::Execute() {}

/** Called once the command ends or is interrupted. */
void IntakeInCommand::End(bool interrupted) {}

/** Returns true when the command should end. */
bool IntakeInCommand::IsFinished() {
  // End the command after the first run
  return true;
}
