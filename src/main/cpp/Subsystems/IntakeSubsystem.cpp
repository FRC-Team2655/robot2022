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

void IntakeSubsystem::RunInatekMotor() {
    intake.Set(INTAKESPEED);
}

/** This method will be called once per scheduler run */
void IntakeSubsystem::Periodic() {}

/** Controls the Solenoid to bring the intake out */
void IntakeSubsystem::IntakeOut() {
    intakeSol.Set(frc::DoubleSolenoid::Value::kForward);
}

/** Controls the Solenoid to bring the intake in */
void IntakeSubsystem::IntakeIn() {
    intakeSol.Set(frc::DoubleSolenoid::Value::kReverse);
}
