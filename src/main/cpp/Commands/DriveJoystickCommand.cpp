/**
 * @file Robot.cpp
 * @date 1/13/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Source code dealing with driving the robot by joystick control.
**/

#include "Commands/DriveJoystickCommand.h"

#include "Robot.h"



/** The constructor of the DriveJoystickCommand */
DriveJoystickCommand::DriveJoystickCommand() {
  /** This command requires control of the drive base */
  AddRequirements(&Robot::driveBase);
}

/** @brief Called when the command is initially scheduled. 
 * @return void
*/
void DriveJoystickCommand::Initialize() {}

/** @brief Called repeatedly when this Command is scheduled to run 
 * @return void
*/
void DriveJoystickCommand::Execute() {
  #if USINGRUMBLE
  /** Scaling the raw joystick trigger inputs */
  double rawForward = (Robot::input.joystick->GetRawAxis(2) + 1) / 2;
  double rawBackward = (Robot::input.joystick->GetRawAxis(3) + 1) / 2;
  #else
  /** Scaling the raw joystick trigger inputs */
  double rawForward = (Robot::input.joystick->GetRawAxis(3) + 1) / 2;
  double rawBackward = (Robot::input.joystick->GetRawAxis(4) + 1) / 2;
  #endif

  /** Defining the deadband */
  double deadband = 0.1;

  /** The direction the robot will be driving in: forward or backward */
  double driveDirection;

  /** If both buttons are pressed, do nothing. */
  if (rawForward > deadband && rawBackward > deadband) driveDirection = 0;
  /** If we are driving forward, set the drive direction to forward */
  else if (rawForward > deadband) driveDirection = rawForward;
  /** If we are driving backward, set the drive direction to backward */
  else if (rawBackward > deadband) driveDirection = -rawBackward;

  /** If the driving style is cubic, use the team2655 library to drive cubic (smooth "flat" part at 50% velocity). */
  #if ISDRIVINGCUBIC
  double rotate = -Robot::driveBase.turningSpeed * team2655::jshelper::getAxisValue(Robot::input.rotateAxisConfig, Robot::input.joystick->GetRawAxis(0));
  double power = team2655::jshelper::getAxisValue(Robot::input.driveAxisConfig, driveDirection);
  #else
  /** If the driving style is linear, drive linearly */
  double rotate = -Robot::driveBase.turningSpeed * Robot::input.joystick->GetRawAxis(0);
  double power = driveDirection;
  #endif

  #if USINGRUMBLE
  if (driveDirection >= 0.5) {
    Robot::input.joystick->SetRumble(frc::GenericHID::RumbleType::kLeftRumble, std::abs(driveDirection));
    Robot::input.joystick->SetRumble(frc::GenericHID::RumbleType::kRightRumble, std::abs(driveDirection));
  }else{
    Robot::input.joystick->SetRumble(frc::GenericHID::RumbleType::kLeftRumble, 0);
    Robot::input.joystick->SetRumble(frc::GenericHID::RumbleType::kRightRumble, 0);
  }
  #endif

	Robot::driveBase.ArcadeDrive(power, rotate);
}

/** @brief Called once the command ends or is interrupted. 
 * @return void
*/
void DriveJoystickCommand::End(bool interrupted) {}

/** @brief Returns true when the command should end. 
 * @return Whether the command should finish.
*/
bool DriveJoystickCommand::IsFinished() {
  return false;
}
