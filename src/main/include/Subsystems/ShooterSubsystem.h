/**
 * @file ShooterSubsystem.h
 * @date 1/18/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Defines the ShooterSubsystem class.
**/

#pragma once

#include <rev/CANSparkMax.h>
#include <frc2/command/SubsystemBase.h>
#include <RobotMap.h>

/** Shooter subsystem controlls the shooter */
class ShooterSubsystem : public frc2::SubsystemBase {
 public:
  ShooterSubsystem();

  void Periodic() override;

  void RunShooterPercentage(double percentage);

  void RunShooterVelocity(double velocity);

  double GetShooterVelocity();

  /** PID Controller for the shooter */
  rev::SparkMaxPIDController shooterPID = shooter1.GetPIDController();

 private:
 /** First shooter motor controller definition */
  rev::CANSparkMax shooter1 {SHOOTER1, rev::CANSparkMax::MotorType::kBrushless};
  /** Second shooter motor controller definition */
  rev::CANSparkMax shooter2 {SHOOTER2, rev::CANSparkMax::MotorType::kBrushless};

  /** Shooter motor controller 1 encoder definition */
  rev::SparkMaxRelativeEncoder shooterEncoder = shooter1.GetEncoder();
};
