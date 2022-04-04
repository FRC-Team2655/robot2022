/**
 * @file RunClimberIndividuallyCommand.cpp
 * @date 4/4/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Source code dealing with running the climber arms individually
**/

#include "Commands/RunClimberIndividuallyCommand.h"

#include "Robot.h"

/** Constructor for the RunClimberIndividuallyCommand class */
RunClimberIndividuallyCommand::RunClimberIndividuallyCommand(bool isLeftSide, double upwardSpeed) : isLeftSide(isLeftSide), upwardSpeed(upwardSpeed) {
  // Requires the climber subsystem
  AddRequirements(&Robot::climber);
}

/** @brief Called when the command is initially scheduled.
 * @return void
 */
void RunClimberIndividuallyCommand::Initialize() {
  // Put the climber arms in coast mode
  Robot::climber.SetClimberCoastMode();
}

/** @brief Called repeatedly when this Command is scheduled to run
 * @return void
 */ 
void RunClimberIndividuallyCommand::Execute() {
  // Run the climber arms individually, passing the isLeftSide (whether we are moving the left side individually) 
  // and upwardSpeed (the speed to run the climber individually at) arguments.
  Robot::climber.RunClimberIndividually(isLeftSide, upwardSpeed);
}

/** @brief Called once the command ends or is interrupted.
 * @return void
 */ 
void RunClimberIndividuallyCommand::End(bool interrupted) {
  // Stop the climber from moving
  Robot::climber.StopClimber();

  // Put the climber arms in brake mode.
  Robot::climber.SetClimberBrakeMode();
}

/** @brief Returns true when the command should end.
 * @return Whether the command should finish
 */ 
bool RunClimberIndividuallyCommand::IsFinished() {
  return false;
}
