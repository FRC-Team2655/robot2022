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
  //AddRequirements(&Robot::shooter);
}

/** @brief Called when the command is initially scheduled. 
 * @return void
*/
void RunShooterVelocityCommand::Initialize() {
  std::cout << "Init" << std::endl;
}

/** @brief Called repeatedly when this Command is scheduled to run 
 * @return void
*/
void RunShooterVelocityCommand::Execute() {
  // Run the shooter at the shooter velocity.
  Robot::shooter.RunShooterVelocity(SHOOTERVELOCITY);
  // Run the shooter kicker
  Robot::shooter.RunShooterKicker(SHOOTERKICKERSPEED);

  std::cout << "Execute" << std::endl;
}

/** @brief Called once the command ends or is interrupted. 
 * @return void
*/
void RunShooterVelocityCommand::End(bool interrupted) {
  // Stop the shooter.
  Robot::shooter.RunShooterPercentage(0);
  // Stop the shooter kicker
  Robot::shooter.StopShooterKicker();

  std::cout << "End" << std::endl;
}

/** @brief Returns true when the command should end. 
 * @return Whether the command should finish.
*/
bool RunShooterVelocityCommand::IsFinished() {
  return false;
}
