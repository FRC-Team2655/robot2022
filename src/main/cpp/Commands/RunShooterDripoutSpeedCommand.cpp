/**
 * @file RunShooterDripoutSpeedCommand.cpp
 * @date 3/2/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Source code dealing with shooting the ball out of the shooter at a very slow speed.
**/

#include "Commands/RunShooterDripoutSpeedCommand.h"
#include "Robot.h"
#include "RobotMap.h"

/** Constructor for the RunShooterDripoutSpeed class */
RunShooterDripoutSpeedCommand::RunShooterDripoutSpeedCommand() {
  // Require the shooter for the command
  AddRequirements(&Robot::shooter);
}

/** @brief Called when the command is initially scheduled. 
 * @return void
*/
void RunShooterDripoutSpeedCommand::Initialize() {}

/** @brief Called repeatedly when this Command is scheduled to run 
 * @return void
*/
void RunShooterDripoutSpeedCommand::Execute() {
  // Running the shooter at the "dripout" speed.
  Robot::shooter.RunShooterVelocity(SHOOTERDRIPOUTSPEED);
  // Run the shooter kicker wheel
  Robot::shooter.RunShooterKicker(SHOOTERKICKERSPEED);
}

/** @brief Called once the command ends or is interrupted. 
 * @return void
*/
void RunShooterDripoutSpeedCommand::End(bool interrupted) {
  // Stopping the shooter.
  Robot::shooter.RunShooterPercentage(0);
  // Stop the shooter kicker
  Robot::shooter.StopShooterKicker();
}

/** @brief Returns true when the command should end. 
 * @return Whether the command should finish.
*/
bool RunShooterDripoutSpeedCommand::IsFinished() {
  return false;
}
