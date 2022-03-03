/**
 * @file RunShooterVelocityCommand.cpp
 * @date 3/2/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Source code dealing with running the shooter at a fixed velocity.
**/

#include "Commands/RunShooterVelocityCommand.h"
#include "Robot.h"
#include "RobotMap.h"

/** Constructor for the RunShooterVelocityCommand. */
RunShooterVelocityCommand::RunShooterVelocityCommand() {
  AddRequirements(&Robot::shooter);
}

/** Called when the command is initially scheduled. */
void RunShooterVelocityCommand::Initialize() {}

/** Called repeatedly when this Command is scheduled to run */
void RunShooterVelocityCommand::Execute() {
  // Run the shooter at the shooter velocity.
  Robot::shooter.RunShooterVelocity(SHOOTERVELOCITY);
}

/** Called once the command ends or is interrupted. */
void RunShooterVelocityCommand::End(bool interrupted) {
  // Stop the shooter.
  Robot::shooter.RunShooterPercentage(0);
}

/** Returns true when the command should end. */
bool RunShooterVelocityCommand::IsFinished() {
  return false;
}
