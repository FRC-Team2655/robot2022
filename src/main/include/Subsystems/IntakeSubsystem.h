/**
 * @file IntakeSubsystem.h
 * @date 1/15/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Declaring the IntakeSubsystem.
**/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>
#include "RobotMap.h"

#include <frc/doublesolenoid.h>

/** The intake subsystem has the code that deals with the intake */
class IntakeSubsystem : public frc2::SubsystemBase {
 public:
  IntakeSubsystem();

  void Periodic() override;

  void RunInatekMotor();

  void IntakeOut();
  
  void IntakeIn();

 private:
  /** Intake Motor definition */
  rev::CANSparkMax intake {INTAKEID, rev::CANSparkMax::MotorType::kBrushless};
  /** Intake Solenoid definition */
  frc::DoubleSolenoid intakeSol1 {1, frc::PneumaticsModuleType::REVPH, INTAKESOL1FORWARDPORT, INTAKESOL1REVERSEPORT};
  frc::DoubleSolenoid intakeSol2 {1, frc::PneumaticsModuleType::REVPH, INTAKESOL2FORWARDPORT, INTAKESOL2REVERSEPORT};
};


