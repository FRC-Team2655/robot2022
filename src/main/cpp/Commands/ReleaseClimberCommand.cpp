/**
 * @file ReleaseClimberCommand.cpp
 * @date 3/5/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Source code dealing with releasing the climber and moving it up to the set position using the PID.
**/

#include "Commands/ReleaseClimberCommand.h"
#include <Robot.h>

/** The Constructor for the ReleaseClimberCommand class. */
ReleaseClimberCommand::ReleaseClimberCommand() {
  // This command requires the climber.
  AddRequirements(&Robot::climber);
}

/** @brief Called when the command is initially scheduled. 
 * @return void
*/
void ReleaseClimberCommand::Initialize() {}

/** @brief Called repeatedly when this Command is scheduled to run 
 * @return void
*/
void ReleaseClimberCommand::Execute() {
  // Setting the climber in coast before moving
  Robot::climber.SetClimberCoastMode();

  // Function to run the climber to the position (approx max height) using the PID.
  Robot::climber.ReleaseClimber();
}

/** @brief Called once the command ends or is interrupted. 
 * @return void
*/
void ReleaseClimberCommand::End(bool interrupted) {
  // Stopping the climber
  Robot::climber.StopClimber();

  // Setting the climber back in brake
  Robot::climber.SetClimberBrakeMode();
}

/** @brief Returns true when the command should end. 
 * @return Whether the command should finish
*/
bool ReleaseClimberCommand::IsFinished() {
  return false;
}
