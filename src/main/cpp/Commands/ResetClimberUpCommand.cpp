/**
 * @file ResetClimberUpCommand.cpp
 * @date 3/7/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Source code dealing with resetting the climber encoders in the up position.
**/

#include "Commands/ResetClimberUpCommand.h"
#include "Robot.h"

/** Constructor for the ResetClimberUpCommand class. */
ResetClimberUpCommand::ResetClimberUpCommand() {
  // This class requires the climber
  AddRequirements(&Robot::climber);
}

/** @brief Called when the command is initially scheduled. 
 * @return void
*/
void ResetClimberUpCommand::Initialize() {
  // Run the command to reset the climber encoders in the up position.
  Robot::climber.ResetClimberUp();
}

/** @brief Called repeatedly when this Command is scheduled to run
 * @return void
 */
void ResetClimberUpCommand::Execute() {}

/** @brief Called once the command ends or is interrupted. 
 * @return void
*/
void ResetClimberUpCommand::End(bool interrupted) {}

/** @brief Returns true when the command should end. 
 * @return Whether the command should finish
*/
bool ResetClimberUpCommand::IsFinished() {
  // Returns true so that the command is only run once
  return true;
}
