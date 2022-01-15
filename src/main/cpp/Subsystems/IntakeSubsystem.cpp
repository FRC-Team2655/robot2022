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
