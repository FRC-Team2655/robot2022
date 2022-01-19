/**
 * @file BeltSubsystem.cpp
 * @date 1/18/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Source code for the belt subsystem.
**/

#include "Subsystems/BeltSubsystem.h"

/** Constructor for the belt subsystem */
BeltSubsystem::BeltSubsystem() = default;

/** This method will be called once per scheduler run */
void BeltSubsystem::Periodic() {}

/** Function for running the belts */
void BeltSubsystem::RunBelts() {
    belt1.Set(BELTSPEED);
    belt2.Set(BELTSPEED);
}

