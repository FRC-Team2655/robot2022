/**
 * @file DriveBaseSubsystem.h
 * @date 1/13/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Defines the DriveBaseSubsystem class.
**/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>
#include <frc/drive/DifferentialDrive.h>
#include "RobotMap.h"
#include "Commands/DriveJoystickCommand.h"
#include <frc/motorcontrol/MotorControllerGroup.h>

#include <frc/ADIS16470_IMU.h>

/** The DriveBaseSubsystem class controls the drivebase. */
class DriveBaseSubsystem : public frc2::SubsystemBase {
public:
  DriveBaseSubsystem();

  void ArcadeDrive(double xSpeed, double zRotation);
  void DriveTankPercentage(double leftPercentage, double rightPercentage);

  void SetCoastMode();
  void SetBrakeMode();

  double GetIMUAngle();
  void ResetIMUAngle();

  double GetLeftVelocity();
  double GetRightVelocity();

  double GetLeftEncoderRotations();
  double GetRightEncoderRotations();

  void ResetEncoders();

  void DriveTank(double lVel, double rVel);

private:
  /** Definition for the left leader motor controller on the drivetrain. */
  rev::CANSparkMax leftLeader {LEFTLEADERID, rev::CANSparkMax::MotorType::kBrushless};
  /** Definition for the first left follower motor controller on the drivetrain. */
  rev::CANSparkMax leftFollower1 {LEFTFOLLOWER1ID, rev::CANSparkMax::MotorType::kBrushless};
  /** Definition for the second left follower motor controller on the drivetrain. */
  rev::CANSparkMax leftFollower2 {LEFTFOLLOWER2ID, rev::CANSparkMax::MotorType::kBrushless};

  /** Definition for the right leader motor controller on the drivetrain. */
  rev::CANSparkMax rightLeader {RIGHTLEADERID, rev::CANSparkMax::MotorType::kBrushless};
  /** Definition for the first right follower motor controller on the drivetrain. */
  rev::CANSparkMax rightFollower1 {RIGHTFOLLOWER1ID, rev::CANSparkMax::MotorType::kBrushless};
  /** Definition for the second right follower motor controller on the drivetrain. */
  rev::CANSparkMax rightFollower2 {RIGHTFOLLOWER2ID, rev::CANSparkMax::MotorType::kBrushless};

  /** Grouping the left and right motor controllers */
  frc::MotorControllerGroup leftSide {leftLeader, leftFollower1, leftFollower2};
  frc::MotorControllerGroup rightSide {rightLeader, rightFollower1, rightFollower2};

  /** Creating encoders for the left and right sides of the drive train */
  rev::SparkMaxRelativeEncoder leftEncoder = leftLeader.GetEncoder();
  rev::SparkMaxRelativeEncoder rightEncoder = rightLeader.GetEncoder();

  /** Assigning the motor controllers to the DifferentialDrive */
  frc::DifferentialDrive robotDrive {leftSide, rightSide};

  /** The DriveJoystickCommand instance */
  DriveJoystickCommand driveJoystick;

  /** Creating the IMU instance */
  frc::ADIS16470_IMU imu {};
};