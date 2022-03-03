/**
 * @file RunIntakeRollersCommand.cpp
 * @date 3/2/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Source code dealing with running the intake rollers at a fixed percentage.
**/

#include "Commands/RunIntakeRollersCommand.h"
#include "Robot.h"
#include "RobotMap.h"

/** Constructor for the RunIntakeRollersCommand. */
RunIntakeRollersCommand::RunIntakeRollersCommand() {
  // Requiring the intake subsystem for this command.
  AddRequirements(&Robot::intake);
}

/** @brief Called when the command is initially scheduled. 
 * @return void
*/
void RunIntakeRollersCommand::Initialize() {}

/** @brief Called repeatedly when this Command is scheduled to run 
 * @return void
*/
void RunIntakeRollersCommand::Execute() {
  // Running the intake at a fixed percentage.
  Robot::intake.RunIntakeRollers(INTAKEROLLERSSPEED);
}

/** @brief Called once the command ends or is interrupted. 
 * @return void
*/
void RunIntakeRollersCommand::End(bool interrupted) {
  // Stopping the intake rollers from running.
  Robot::intake.RunIntakeRollers(0);
}

/** @brief Returns true when the command should end. 
 * @return Whether the command should finish.
*/
bool RunIntakeRollersCommand::IsFinished() {
  return false;
}
