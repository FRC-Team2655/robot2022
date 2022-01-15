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

/** The intake subsystem has the code that deals with the intake */
class IntakeSubsystem : public frc2::SubsystemBase {
 public:
  IntakeSubsystem();

  void Periodic() override;

  void RunInatekMotor();

 private:
 rev::CANSparkMax intake {INTAKEID, rev::CANSparkMax::MotorType::kBrushless};
};
