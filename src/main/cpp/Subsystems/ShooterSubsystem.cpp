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
    /** Making shooter 2 follow shooter 1 and inverted*/
    shooter2.Follow(shooter1, true);

    /** Applying the PID value to the shooter */
    shooter1PID.SetP(KPSHOOTER);
    shooter1PID.SetI(KISHOOTER);
    shooter1PID.SetD(KDSHOOTER);
    shooter1PID.SetFF(KFFSHOOTER);
    shooter1PID.SetIZone(0);
    shooter1PID.SetOutputRange(-1, 1);

    // Burn the flash to ensure that the settings are maintained on the shooter motor controllers
    shooter1.BurnFlash();
    shooter2.BurnFlash();
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
    shooter1PID.SetReference(velocity, rev::ControlType::kVelocity);
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

/** @brief Function to set the shooter kicker motor in coast mode
 * @return void
 */ 
void ShooterSubsystem::SetKickerCoastMode() {
    // Setting the kicker in coast mode
    shooterKicker.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
}

/** @brief Function to run the shooter kicker
 * @return void
 */
void ShooterSubsystem::RunShooterKicker() {
    // Running the shooter kicker at a set percentage
    shooterKicker.Set(SHOOTERKICKERSPEED);
} 

/** @brief Function to stop the shooter kicker
 * @return void
 */
void ShooterSubsystem::StopShooterKicker() {
    // Setting the shooter kicker to 0
    shooterKicker.Set(0);
}

double ShooterSubsystem::GetKickerVelocity() {
    return kickerEncoder.GetVelocity();
}