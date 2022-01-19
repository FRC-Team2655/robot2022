/**
 * @file BeltSubsystem.h
 * @date 1/18/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Defines the BeltSubsystem class.
**/

#pragma once

#include <RobotMap.h>
#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>

/** The belt subsystem controlls the belt */
class BeltSubsystem : public frc2::SubsystemBase {
 public:
  BeltSubsystem();

  void Periodic() override;

  void RunBelts();


 private:
 /** First belt motor definition */
  rev::CANSparkMax belt1 {BELTID1, rev::CANSparkMax::MotorType::kBrushless};
  /** Second belt motor controller definition */
  rev::CANSparkMax belt2 {BELTID2, rev::CANSparkMax::MotorType::kBrushless};

};
