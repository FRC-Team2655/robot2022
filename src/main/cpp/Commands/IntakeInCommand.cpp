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
  AddRequirements(&Robot::intake);
}

/** Called when the command is initially scheduled. */
void IntakeInCommand::Initialize() {
  Robot::intake.IntakeIn();
}

/** Called repeatedly when this Command is scheduled to run */
void IntakeInCommand::Execute() {}

/** Called once the command ends or is interrupted. */
void IntakeInCommand::End(bool interrupted) {}

/** Returns true when the command should end. */
bool IntakeInCommand::IsFinished() {
  return false;
}
