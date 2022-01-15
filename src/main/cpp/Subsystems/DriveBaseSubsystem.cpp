/**
 * @file Robot.cpp
 * @date 1/13/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Source code dealing with drivetrain control.
**/

#include "Subsystems/DriveBaseSubsystem.h"

/** The constructor of the drivetrain. */
DriveBaseSubsystem::DriveBaseSubsystem() {
    SetDefaultCommand(driveJoystick);
}

/**
 * @brief Function used to drive the robot with the arcade style.
 * @param xSpeed the speed to drive the robot along the x-axis
 * @param zRotation the rotation to drive the robot about the z-axis
 * @return void
 */ 
void DriveBaseSubsystem::arcadeDrive(double xSpeed, double zRotation) {
    // Drive with arcade style
    robotDrive.ArcadeDrive(xSpeed, zRotation);
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