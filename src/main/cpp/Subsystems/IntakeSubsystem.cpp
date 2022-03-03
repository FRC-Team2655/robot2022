/**
 * @file IntakeSubsystem.h
 * @date 1/15/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Contains the code dealing with intake control.
**/

#include "Subsystems/IntakeSubsystem.h"

/** The intake subsystem constructor */
IntakeSubsystem::IntakeSubsystem() {
}

/** Run the intake rollers at a set speed */
void IntakeSubsystem::RunIntakeRollers() {
    intakeRollers.Set(INTAKESPEED);
}

/** This method will be called once per scheduler run */
void IntakeSubsystem::Periodic() {}

/** Controls the Solenoid to bring the intake out */
void IntakeSubsystem::IntakeOut() {
    intakeSol1.Set(frc::DoubleSolenoid::kForward);
    intakeSol2.Set(frc::DoubleSolenoid::kForward);
}

/** Controls the Solenoid to bring the intake in */
void IntakeSubsystem::IntakeIn() {
    intakeSol1.Set(frc::DoubleSolenoid::kReverse);
    intakeSol2.Set(frc::DoubleSolenoid::kReverse);
}
