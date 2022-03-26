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

  void SetShooterBrakeMode();
  void SetShooterCoastMode();

  void SetKickerCoastMode();

  void RunShooterKicker(double kickerSpeed);
  void StopShooterKicker();

  double GetKickerVelocity();

  /** PID Controller for the shooter */
  rev::SparkMaxPIDController shooter1PID = shooter1.GetPIDController();
  rev::SparkMaxPIDController shooter2PID = shooter2.GetPIDController();

  double shooterKickerSpeed = 0.4;
  double shooterSpeed = 3600;

  /** A boolean to track whether the shooter is at maximum velocity. True is at max, false is not. */
  bool isShooterAtMax = false;
  /** A boolean to track whether the shooter is running. True is running, false is not. */
  bool isShooterRunning = false;

 private:
 /** First shooter motor controller definition */
  rev::CANSparkMax shooter1 {SHOOTER1, rev::CANSparkMax::MotorType::kBrushless};
  /** Second shooter motor controller definition */
  rev::CANSparkMax shooter2 {SHOOTER2, rev::CANSparkMax::MotorType::kBrushless};

  /** Motor controller for the shooter kicker */
  rev::CANSparkMax shooterKicker {SHOOTERKICKERID, rev::CANSparkMax::MotorType::kBrushless};

  /** Shooter motor controller 1 encoder definition */
  rev::SparkMaxRelativeEncoder shooterEncoder = shooter1.GetEncoder();

  rev::SparkMaxRelativeEncoder kickerEncoder = shooterKicker.GetEncoder();
};
