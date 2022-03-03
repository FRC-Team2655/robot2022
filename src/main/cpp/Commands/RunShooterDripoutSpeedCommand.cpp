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

/** Called when the command is initially scheduled. */
void RunShooterDripoutSpeedCommand::Initialize() {}

/** Called repeatedly when this Command is scheduled to run */
void RunShooterDripoutSpeedCommand::Execute() {
  // Running the shooter at the "dripout" speed.
  Robot::shooter.RunShooterVelocity(SHOOTERDRIPOUTSPEED);
}

/** Called once the command ends or is interrupted. */
void RunShooterDripoutSpeedCommand::End(bool interrupted) {
  // Stopping the shooter.
  Robot::shooter.RunShooterPercentage(0);
}

/** Returns true when the command should end. */
bool RunShooterDripoutSpeedCommand::IsFinished() {
  return false;
}
