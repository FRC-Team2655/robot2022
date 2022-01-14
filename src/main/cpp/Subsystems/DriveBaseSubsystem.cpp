/**
 * @file Robot.cpp
 * @date 1/13/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Source code dealing with drivetrain control.
**/

#include "../../include/Subsystems/DriveBaseSubsystem.h"

/**
 * @brief Function used to drive the robot with the arcade style.
 * @return void
 */ 
void DriveBaseSubsystem::arcadeDrive() {
    // Drive with arcade style
    robotDrive.ArcadeDrive(joystick.GetY(), joystick.GetZ());
}

/**
 * @brief Function used to set all the motor controllers in coast mode.
 * @return void
 */ 
void DriveBaseSubsystem::setCoastMode() {
    /** Set the Motor Controllers in Coast Mode */
   leftLeader.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
   leftFollower1.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
   leftFollower2.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);

   rightLeader.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
   rightFollower1.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
   rightFollower2.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
}