/**
 * @file DriveBaseSubsystem.cpp
 * @date 1/13/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Source code dealing with drivetrain control.
**/

#include "Subsystems/DriveBaseSubsystem.h"


/** The constructor of the drivetrain. */
DriveBaseSubsystem::DriveBaseSubsystem() {

    /** Set the DriveJoystickCommand as the default command to be run */
    SetDefaultCommand(driveJoystick);

    /** Make the followers follow the leaders */
    leftFollower1.Follow(leftLeader);
    leftFollower2.Follow(leftLeader);
    rightFollower1.Follow(rightLeader);
    rightFollower2.Follow(rightLeader);

    /** Assigning the PID loop values for the left side of the drivetrain */
    leftPID.SetP(KPLEFT);
    leftPID.SetI(KILEFT);
    leftPID.SetD(0);
    leftPID.SetFF(1/LMAXVELOCITY);
    leftPID.SetIZone(0);
    leftPID.SetOutputRange(-1, 1);

    /** Assigning the PID loop values for the right side of the drivetrain */
    rightPID.SetP(KPRIGHT);
    rightPID.SetI(KIRIGHT);
    rightPID.SetD(0);
    rightPID.SetFF(1/RMAXVELOCITY);
    rightPID.SetIZone(0);
    rightPID.SetOutputRange(-1, 1);
}

/**
 * @brief Function used to drive the robot with the arcade style.
 * @param xSpeed the speed to drive the robot along the x-axis
 * @param zRotation the rotation to drive the robot about the z-axis
 * @return void
 */ 
void DriveBaseSubsystem::ArcadeDrive(double xSpeed, double zRotation) {
    // Drive with arcade style
    robotDrive.ArcadeDrive(xSpeed, zRotation);
}

/**
 * @brief Run each side of the drivetrain independently at a fixed percentage.
 * @param leftPercentage The percentage to run the left side at.
 * @param rightPercentage The percentage to run the right side at.
 * @return void
 */ 
void DriveBaseSubsystem::DriveTankPercentage(double leftPercentage, double rightPercentage) {
    /** Set the motors to run at the percentage value on the left side of the drivetrain */
	leftLeader.Set(leftPercentage);
	leftFollower1.Set(leftPercentage);
	leftFollower2.Set(leftPercentage);

    /** Set the motors to run at the percentage value on the right side of the drivetrain */
	rightLeader.Set(rightPercentage);
	rightFollower1.Set(rightPercentage);
	rightFollower2.Set(rightPercentage);
}

/**
 * @brief Function used to set all the motor controllers in coast mode.
 * @return void
 */ 
void DriveBaseSubsystem::SetCoastMode() {
    /** Set the Motor Controllers in Coast Mode */
   leftLeader.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
   leftFollower1.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
   leftFollower2.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);

   rightLeader.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
   rightFollower1.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
   rightFollower2.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
}

/**
 * @brief Used to get the current angle of the IMU.
 * @return The IMU angle in degrees.
 */ 
units::degree_t DriveBaseSubsystem::GetIMUAngle() {
    return imu.GetAngle();
}

/**
 * @brief Used to reset the angle of the IMU.
 * @return void
 */ 
void DriveBaseSubsystem::ResetIMUAngle() {
    imu.Reset();
}