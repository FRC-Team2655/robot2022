/**
 * @file ShooterSubsystem.cpp
 * @date 1/18/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Source code for the shooter subsystem.
**/
#include "Subsystems/ShooterSubsystem.h"

#include <frc/motorcontrol/Spark.h>

/** Constructor for the shooter subsystem */
ShooterSubsystem::ShooterSubsystem() {
    shooter2.SetInverted(true);

    /** Making shooter 2 follow shooter 1 */
    shooter2.Follow(shooter1);

    /** Applying the PID value to the shooter */
    shooterPID.SetP(KPSHOOTER);
    shooterPID.SetI(KISHOOTER);
    shooterPID.SetD(KDSHOOTER);
    shooterPID.SetFF(KFFSHOOTER);
    shooterPID.SetIZone(0);
    shooterPID.SetOutputRange(-1, 1);
}


/** @brief This method will be called once per scheduler run 
 * @return void
*/
void ShooterSubsystem::Periodic() {}

/** @brief Running the shooter at a fixed percentage 
 * @param percentage The percentage to run the shooter at.
 * @return void
*/
void ShooterSubsystem::RunShooterPercentage(double percentage) {
    shooter1.Set(percentage);
    shooter2.Set(percentage);
}

/** @brief Running the shooter using the PID loop 
 * @param velocity The velocity to run the shooter at.
 * @return void
*/
void ShooterSubsystem::RunShooterVelocity(double velocity) {
    shooterPID.SetReference(velocity, rev::ControlType::kVelocity);
}

/** @brief Get the current shooter velocity in RPM.
 * @return The shooter velocity in RPM as a double.
 */
double ShooterSubsystem::GetShooterVelocity() {
    return shooterEncoder.GetVelocity();
}

/** @brief Setting the shooter into brake mode.
 * @return void
 */ 
void ShooterSubsystem::SetShooterBrakeMode() {
    // Setting the shooter motor controllers into brake mode.
    shooter1.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
    shooter2.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
}

/** @brief Setting the shooter into coast mode.
 * @return void
 */ 
void ShooterSubsystem::SetShooterCoastMode() {
    // Setting the shooter motor controllers into coast mode.
    shooter1.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
    shooter2.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
}