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


/** This method will be called once per scheduler run */
void ShooterSubsystem::Periodic() {}

/** Running the shooter at a fixed percentage */
void ShooterSubsystem::RunShooterPercentage(double percentage) {
    shooter1.Set(percentage);
    shooter2.Set(percentage);
}

/** Running the shooter using the PID loop */
void ShooterSubsystem::RunShooterVelocity(double velocity) {
    shooterPID.SetReference(velocity, rev::ControlType::kVelocity);
}
