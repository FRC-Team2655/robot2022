/**
 * @file LimelightSubsystem.cpp
 * @date 1/20/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Source code for the limelight subsystem.
**/

#include "Subsystems/LimelightSubsystem.h"

/** Constructor for the limlight subsystem */
LimelightSubsystem::LimelightSubsystem() {};

/** @brief This method will be called once per scheduler run 
 * @return void
*/
void LimelightSubsystem::Periodic() {}

/** @brief Updates the values from the limelight periodically 
 * @return void
*/
void LimelightSubsystem::UpdateValues() {
  /*double targetOffsetAngle_Horizontal = limelightTable->GetNumber("tx",0.0);
  double targetOffsetAngle_Vertical = limelightTable->GetNumber("ty",0.0);
  double targetArea = limelightTable->GetNumber("ta",0.0);
  double targetSkew = limelightTable->GetNumber("ts",0.0);
  double identifyTarget = limelightTable->GetNumber("tv", 0.0);*/
}

/** @brief Prints the Limelight's values 
 * @return void
*/
void LimelightSubsystem::PrintValues() {
    /*std::cout << "tx: " << targetOffsetAngle_Horizontal << std::endl;
    std::cout << "ty: " << targetOffsetAngle_Vertical << std::endl;
    std::cout << "ta: " << targetArea << std::endl;
    std::cout << "ts: " << targetSkew << std::endl;
    std::cout << "tv: " << identifyTarget << std::endl;*/
}
