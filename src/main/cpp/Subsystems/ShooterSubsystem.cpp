/**
 * @file ShooterSubsystem.cpp
 * @date 1/18/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Source code for the shooter subsystem.
**/
#include "Subsystems/ShooterSubsystem.h"

/** Constructor for the shooter subsystem */
ShooterSubsystem::ShooterSubsystem() {
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
