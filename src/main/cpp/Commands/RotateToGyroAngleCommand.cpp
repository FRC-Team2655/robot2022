/**
 * @file RotateToGyroAngleCommand.cpp
 * @date 3/17/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Source code dealing with movng the robot to a gven gyro angle.
**/

#include "commands/RotateToGyroAngleCommand.h"
#include <Robot.h>

/** The constructor of the RotateToGyroAngleCommand. */
RotateToGyroAngleCommand::RotateToGyroAngleCommand(double TargetAngle) : TargetAngle(TargetAngle){}

/** @brief Called when the command is initially scheduled. 
 * @return void
*/
void RotateToGyroAngleCommand::Initialize() {
  Robot::driveBase.SetCoastMode();

  /* Get the initial IMU angle */
  double initialGyroAngle = Robot::driveBase.GetIMUAngle();
  
  /* Find the delta from the target angle */
  double delta = (TargetAngle - initialGyroAngle);

  /* Apply the delta to the base command */
  baseCmd.degrees = delta;

  /* Run base command initialize */
  baseCmd.Initialize();
}

/** @brief Called repeatedly when this Command is scheduled to run
 * @return void
 */ 
void RotateToGyroAngleCommand::Execute() {
  baseCmd.Execute();
}

/** @brief Called once the command ends or is interrupted.
 * @return void
 */ 
void RotateToGyroAngleCommand::End(bool interrupted) {
  baseCmd.End(interrupted);
}

/** @brief Returns true when the command should end.
 * @return Whether the command is finished
 */ 
bool RotateToGyroAngleCommand::IsFinished() {
  return baseCmd.IsFinished();
}
