/**
 * @file MoveClimberUpCommand.cpp
 * @date 3/5/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Source code dealing with moving the climber up at a fixed percentage.
**/

#include "Commands/MoveClimberUpCommand.h"
#include "Robot.h"

/** Constructor for the MoveClimberUpCommand class. */
MoveClimberUpCommand::MoveClimberUpCommand(double percentage) : percentage(percentage) {
  // This class requires the climber.
  AddRequirements(&Robot::climber);
}

/** @brief Called when the command is initially scheduled. 
 * @return void
*/
void MoveClimberUpCommand::Initialize() {}

/** @brief Called repeatedly when this Command is scheduled to run 
 * @return void
*/
void MoveClimberUpCommand::Execute() {
  // Setting the climber in coast before moving
  Robot::climber.SetClimberCoastMode();

  // Running the climber at the fixed percentage
  Robot::climber.MoveClimberUp(percentage);
}

/** @brief Called once the command ends or is interrupted. 
 * @return void
*/
void MoveClimberUpCommand::End(bool interrupted) {
  // Stopping the climber.
  Robot::climber.StopClimber();

  // Setting the climber back in brake
  Robot::climber.SetClimberBrakeMode();
}

/** @brief Returns true when the command should end. 
 * @return Whether the command should finish
*/
bool MoveClimberUpCommand::IsFinished() {
  return false;
}
