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

#include <frc/ADIS16470_IMU.h>

/** The DriveBaseSubsystem class controls the drivebase. */
class DriveBaseSubsystem : public frc2::SubsystemBase {
public:
  DriveBaseSubsystem();

  void ArcadeDrive(double xSpeed, double zRotation);
  void DriveTankPercentage(double leftPercentage, double rightPercentage);
  void SetCoastMode();

  units::degree_t GetIMUAngle();
  void ResetIMUAngle();

  /** PID controller for the left side of the drivetrain */
  rev::SparkMaxPIDController leftPID = leftLeader.GetPIDController();
  /** PID controller for the right side of the drivetrain */
  rev::SparkMaxPIDController rightPID = rightLeader.GetPIDController();
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

  /** Assigning the motor controllers to the DifferentialDrive */
  frc::DifferentialDrive robotDrive {leftLeader, rightLeader};

  /** The DriveJoystickCommand instance */
  DriveJoystickCommand driveJoystick;

  /** Creating the IMU instance */
  frc::ADIS16470_IMU imu {};
};