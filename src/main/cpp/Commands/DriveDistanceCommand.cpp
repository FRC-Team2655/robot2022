/**
 * @file DriveDistanceCommand.cpp
 * @date 3/17/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Source code dealing with driving the robot a given amount of distance in inches
**/

#include "commands/DriveDistanceCommand.h"
#include "Robot.h"

/** The constructor of the DriveDistanceCommand class */
DriveDistanceCommand::DriveDistanceCommand(double distance) : distance(distance) {
  AddRequirements(&Robot::driveBase);
  maxSpeed = 1500;
}

/** @brief Called when the command is initially scheduled.
 * @return void
 */ 
void DriveDistanceCommand::Initialize() {
  Robot::driveBase.DriveTankPercentage(0, 0);
  Robot::driveBase.ResetEncoders();
  currentDistance = 0;
  currentSpeed = 0;
  gyroStartAngle = Robot::driveBase.GetIMUAngle();
  gyroAngle = gyroStartAngle;
  /* Determine direction */
  goingForward = true;
  if(distance < 0)
    goingForward = false;
}

/** @brief Called repeatedly when this Command is scheduled to run
 * @return void
 */ 
void DriveDistanceCommand::Execute() {
  double remainingDistance;
  double gyroError, gyroSpeedCompensation;
  double leftSpeed, rightSpeed;

  //get travelled distance from encoders
  currentDistance = GetCurrentDistance();
  //calculate remaining distance (absolute value)
  remainingDistance = std::abs(distance - currentDistance);

  if(remainingDistance < rampDownDistance)
  {
    /* Slowing down. Want to go from maxspeed to 0 over 1 meter */
    currentSpeed -= (P_encoders * (rampDownDistance - remainingDistance));
    if(currentSpeed < minSpeed)
      currentSpeed = minSpeed;
  }
  else
  {
    /* Ramping up speed */
    if(currentSpeed < minSpeed)
    {
      currentSpeed = minSpeed;
    }
    else if(currentSpeed < maxSpeed)
    {
      currentSpeed += speedStep;
    }
    else
    {
      currentSpeed = maxSpeed;
    }
  }
  
  /* handle gyro compensation */

  /* Resample the gyro */
  gyroAngle = Robot::driveBase.GetIMUAngle();

  /* Calculate the error (in degrees) */
  gyroError = gyroAngle - gyroStartAngle;
  
  /* Set gyro speed compensation value (gyro P term * error) */
  gyroSpeedCompensation = (P_gyro * gyroError);

  /* Apply gyro compensation */
  if(goingForward)
  {
    leftSpeed = currentSpeed + gyroSpeedCompensation;
    rightSpeed = currentSpeed - gyroSpeedCompensation;
  }
  else
  {
    leftSpeed = currentSpeed - gyroSpeedCompensation;
    rightSpeed = currentSpeed + gyroSpeedCompensation;
  }

  /* Check speed capping */
  if(leftSpeed > maxSpeed)
  {
    rightSpeed *= (maxSpeed / leftSpeed);
    leftSpeed = maxSpeed;
  }
  if(rightSpeed > maxSpeed)
  {
    leftSpeed *= (maxSpeed / rightSpeed);
    rightSpeed = maxSpeed;
  }

  /* Apply to drive base (update velocity set point) */
  if(goingForward)
      Robot::driveBase.DriveTank(-leftSpeed, -rightSpeed);
  else
      Robot::driveBase.DriveTank(leftSpeed, rightSpeed);

  //std::cout << "Left: " << leftSpeed << ", " << "Right: " << rightSpeed << ", " << "Gyro Error: " << gyroError << std::endl;
  std::cout << "Left: " << Robot::driveBase.GetLeftEncoderRotations() << ", Right: " << Robot::driveBase.GetRightEncoderRotations() << ", Current Distance: " << currentDistance
  << ", Gyro Error:" << gyroError << std::endl;
}

/** @brief Called once the command ends or is interrupted.
 * @return void
 */ 
void DriveDistanceCommand::End(bool interrupted) {
  Robot::driveBase.DriveTank(0, 0);
}

/** @brief Returns true when the command should end.
 * @return Whether the command should finish
 */ 
bool DriveDistanceCommand::IsFinished() {
  if(goingForward)
    return currentDistance >= distance;
  else
    return currentDistance <= distance;
 }

 double DriveDistanceCommand::GetCurrentDistance()
 {
   double averageRotations;
   averageRotations = Robot::driveBase.GetRightEncoderRotations() + Robot::driveBase.GetLeftEncoderRotations();
   averageRotations *= 0.5;
   //scale to inches. Wheels are 6" diameter
   return averageRotations * 3.141592 * 6;
 }