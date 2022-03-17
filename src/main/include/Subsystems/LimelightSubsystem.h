/**
 * @file LimelightSubsystem.h
 * @date 1/20/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Defines the LimelightSubsystem class.
**/
#pragma once

#include "frc/smartdashboard/Smartdashboard.h"
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableValue.h"
#include "wpi/span.h"
#include <frc2/command/SubsystemBase.h>
#include <iostream>

/** Class to control the limelight */
class LimelightSubsystem : public frc2::SubsystemBase {
 public:
  LimelightSubsystem();

  void Periodic() override;

  void UpdateValues();
  void PrintValues();

  /** Creating the limelight network table */ 
  //std::shared_ptr<nt::NetworkTable> limelightTable = nt::NetworkTableInstance::GetDefault().GetTable("limelight");

  /** getting the data from the network table for the limelight */
  /*double targetOffsetAngle_Horizontal = limelightTable->GetNumber("tx",0.0);
  double targetOffsetAngle_Vertical = limelightTable->GetNumber("ty",0.0);
  double targetArea = limelightTable->GetNumber("ta",0.0);
  double targetSkew = limelightTable->GetNumber("ts",0.0);
  int identifyTarget = limelightTable->GetNumber("tv", 0);*/

 private:
};
