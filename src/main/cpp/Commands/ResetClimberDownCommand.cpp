/**
 * @file ResetClimberUpCommand.cpp
 * @date 3/7/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Source code dealing with resetting the climber encoders in the down position.
**/

#include "Commands/ResetClimberDownCommand.h"
#include "Robot.h"

/** The constructor of the ResetClimberDownCommand class */
ResetClimberDownCommand::ResetClimberDownCommand() {
  // This command requires the climber
  AddRequirements(&Robot::climber);
}

/** @brief Called when the command is initially scheduled. 
 * @return void
*/
void ResetClimberDownCommand::Initialize() {
  // Run the function to reset the climber encoders in the down position.
  Robot::climber.ResetClimberDown();
}

/** @brief Called repeatedly when this Command is scheduled to run 
 * @return void
*/
void ResetClimberDownCommand::Execute() {}

/** @brief Called once the command ends or is interrupted. 
 * @return void
*/
void ResetClimberDownCommand::End(bool interrupted) {}

/** @brief Returns true when the command should end. 
 * @return Whether the command should finish
*/
bool ResetClimberDownCommand::IsFinished() {
  // Return true so that the command is only run once.
  return true;
}
