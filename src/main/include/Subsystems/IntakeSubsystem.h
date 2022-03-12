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

#include <frc/DoubleSolenoid.h>

/** The intake subsystem has the code that deals with the intake */
class IntakeSubsystem : public frc2::SubsystemBase {
 public:
  IntakeSubsystem();

  void Periodic() override;

  void RunIntakeRollers(double percentage);

  void IntakeOut();
  
  void IntakeIn();

  void SetIntakeRollersCoastMode();
  void SetIntakeRollersBrakeMode();

  /** Boolean variable to track whether the intake is out or in */
  bool isIntakeIn = false;

 private:
  /** Intake Motor definition */
  rev::CANSparkMax intakeRollers {INTAKEROLLERSID, rev::CANSparkMax::MotorType::kBrushless};
  /** Intake Solenoid definition */
  frc::DoubleSolenoid intakeLeftSol {1, frc::PneumaticsModuleType::REVPH, INTAKELEFTSOLFORWARDPORT, INTAKELEFTSOLREVERSEPORT};
  frc::DoubleSolenoid intakeRightSol {1, frc::PneumaticsModuleType::REVPH, INTAKERIGHTSOLFORWARDPORT, INTAKERIGHTSOLREVERSEPORT};
};


