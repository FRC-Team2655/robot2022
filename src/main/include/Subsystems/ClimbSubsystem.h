/**
 * @file ClimbSubsystem.h
 * @date 3/5/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Declaring the Climb class.
**/
#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>
#include <RobotMap.h>

/** the climb subsystem operates the climber */
class ClimbSubsystem : public frc2::SubsystemBase {
 public:
  ClimbSubsystem();

  void MoveClimberUp(double percentage);
  void MoveClimberDown(double percentage);

  void ReleaseClimber();

  void SetClimberBrakeMode();
  void SetClimberCoastMode();

  void StopClimber();

  double GetLeftClimberPosition();
  double GetRightClimberPosition();

  void ResetClimberDown();
  void ResetClimberUp();

  void Periodic() override;

 private:

 /** Motor controller definitions for the left and right climbers */
  rev::CANSparkMax leftClimber {LEFTCLIMBERID, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax rightClimber {RIGHTCLIMBERID, rev::CANSparkMax::MotorType::kBrushless};

/** PID definintions for the left and right climbers */
  rev::SparkMaxPIDController leftClimbPID = leftClimber.GetPIDController();
  rev::SparkMaxPIDController rightClimbPID = rightClimber.GetPIDController();

/** Relative Encoder definitions for the left and right climbers */
  rev::SparkMaxRelativeEncoder leftClimberEncoder = leftClimber.GetEncoder();
  rev::SparkMaxRelativeEncoder rightClimberEncoder = rightClimber.GetEncoder();
};
