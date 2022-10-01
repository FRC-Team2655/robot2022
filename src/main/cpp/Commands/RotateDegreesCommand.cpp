/**
 * @file RotateDegreesCommand.cpp
 * @date 3/17/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Source code dealing with rotating a robot a given amount of degrees.
**/

#include "commands/RotateDegreesCommand.h"
#include "Robot.h"

/** The constructor of the RotateDegreesCommand class */
RotateDegreesCommand::RotateDegreesCommand(double degrees) : degrees(degrees) {}

/** @brief Called when the command is initially scheduled.
 * @return void
 */ 
void RotateDegreesCommand::Initialize() {
  Robot::driveBase.SetCoastMode();

  /* First mod by 360 to get to range -360 - 360 */
  degrees = std::fmod(degrees, 360);

  /* Correct for out of range degree values by add/subtracting full rotation */
  if(degrees < -180)
    degrees = degrees + 360;
  else if(degrees > 180)
    degrees = degrees - 360;

  /* degrees is now in range [-180 - 180]. Get the gyro start angle */
  startAngle = Robot::driveBase.GetIMUAngle();
  currentAngle = startAngle;

  /* Find the target angle */
  targetAngle = startAngle + degrees;

  /* Find rotate direction */
  if(degrees < 0)
    turnRight = true;
  else
    turnRight = false;

  /* Init the current RPM value to min */
  currentSpeed = minSpeed;
}

/** @brief Called repeatedly when this Command is scheduled to run
 * @return void
 */ 
void RotateDegreesCommand::Execute() {
  double remainingAngle;
  double rampDownCompensation;

  /* Get the IMU angle */
  currentAngle = Robot::driveBase.GetIMUAngle();
  
  /* Calculate remaining angle */
  remainingAngle = std::abs(targetAngle - currentAngle);

  if(remainingAngle < rampdownStartAngle)
  {
    /* Need to start slowing down */
    rampDownCompensation = (rampdownStartAngle - remainingAngle);
    rampDownCompensation *= P_gyro;
    currentSpeed -= rampDownCompensation;
  }
  else
  {
    if(currentSpeed < maxSpeed)
    {
      /* Ramp up motor speed */
      currentSpeed += rampUpIncrement;
    }
    else
    {
      /* Cap at max */
      currentSpeed = maxSpeed;
    }
  }

  /* Apply speed clamping */
  if(currentSpeed < minSpeed)
    currentSpeed = minSpeed;
  if(currentSpeed > maxSpeed)
    currentSpeed = maxSpeed;
  
  /* Change direction (if needed) */
  if(turnRight)
  {
    /* Negative angle provided */
    if(currentAngle < targetAngle)
      turnRight = false;
  }
  else
  {
    /* Positive angle provided */
    if( currentAngle > targetAngle)
      turnRight = true;
  }
  

  std::cout << "Current Speed: " << currentSpeed << " Remaining Angle: " << remainingAngle << "Turning Right: " << turnRight << std::endl;


  /* Apply te current speed value to motors */
  if(turnRight)
  {
    Robot::driveBase.DriveTank(-currentSpeed, currentSpeed);
  }
  else
  {
    Robot::driveBase.DriveTank(currentSpeed, -currentSpeed);
  }
}

/** @brief Called once the command ends or is interrupted.
 * @return void
 */ 
void RotateDegreesCommand::End(bool interrupted) {
  Robot::driveBase.DriveTank(0, 0);

  std::cout << "end" << std::endl;
}

/** @brief Returns true when the command should end.
 * @return Whether the command should finish
 */ 
bool RotateDegreesCommand::IsFinished() {
  static bool isAngleMet = false;

  /* Get the error */
  double angleError = std::abs(currentAngle - targetAngle);

  // If we are "sweeping" through the desired angle, do not return.
  if (angleError < 1.0) {
    if (isAngleMet) {
      return true;
    }else{
      isAngleMet = true;
    }
  }

  return false;
}
