/**
 * @file MoveClimberDownCommand.cpp
 * @date 3/5/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Source code dealing with moving the climber down at a fixed percentage.
**/

#include "Commands/MoveClimberDownCommand.h"
#include "Robot.h"

/** The constructor for the MoveClimberDownCommand class */
MoveClimberDownCommand::MoveClimberDownCommand(double percentage) : percentage(percentage) {
  // This command requires the climber.
  AddRequirements(&Robot::climber);
}

/** Called when the command is initially scheduled. */
void MoveClimberDownCommand::Initialize() {}

/** Called repeatedly when this Command is scheduled to run */
void MoveClimberDownCommand::Execute() {
  // Setting the climber in coast before moving
  Robot::climber.SetClimberCoastMode();

  // Move the climber down.
  Robot::climber.MoveClimberDown(percentage);
}

/** Called once the command ends or is interrupted. */
void MoveClimberDownCommand::End(bool interrupted) {
  // Stopping the climber.
  Robot::climber.StopClimber();

  // Setting the climber back in brake
  Robot::climber.SetClimberBrakeMode();
}

/** Returns true when the command should end. */
bool MoveClimberDownCommand::IsFinished() {
  return false;
}
