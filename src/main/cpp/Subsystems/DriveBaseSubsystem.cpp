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

    /** Inverting the right side of the drive train so that both sides are in the same direction. */
    rightSide.SetInverted(true);
}

/**
 * @brief Function used to drive the robot with the arcade style. Takes care of drive base tuning as well.
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
 * @brief Function used to set all the motor controllers in brake mode.
 * @return void
 */ 
void DriveBaseSubsystem::SetBrakeMode() {
    /** Set the Motor Controllers in Coast Mode */
   leftLeader.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
   leftFollower1.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
   leftFollower2.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);

   rightLeader.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
   rightFollower1.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
   rightFollower2.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
}

/**
 * @brief Used to get the current angle of the IMU.
 * @return The IMU angle in degrees.
 */ 
double DriveBaseSubsystem::GetIMUAngle() {
    units::degree_t angleDegrees = imu.GetAngle();
    double angle = angleDegrees.value();

    return angle;
}

/**
 * @brief Used to reset the angle of the IMU.
 * @return void
 */ 
void DriveBaseSubsystem::ResetIMUAngle() {
    imu.Reset();
}

/** @brief Function to get the velocity of the left side of the drive train in RPM
 * @return The velocity of the left side in RPM
 */ 
double DriveBaseSubsystem::GetLeftVelocity() {
    return leftEncoder.GetVelocity();
}

/** @brief Function to get the velocity of the right side of the drive train in RPM
 * @return The velocity of the right side in RPM
 */ 
double DriveBaseSubsystem::GetRightVelocity() {
    return rightEncoder.GetVelocity();
}