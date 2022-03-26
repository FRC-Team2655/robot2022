/**
 * @file Autonomous.cpp
 * @date 2/23/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Source code for the Autonomous routines.
**/

#include "Autonomous.h"

/** The constructor for the Autonomous class */
Autonomous::Autonomous() {}

frc2::Command* Autonomous::DriveBackwards() {
    /* Test auto to drive backwards */
    frc2::SequentialCommandGroup* routine = new frc2::SequentialCommandGroup();
    /* Drive backwards 5 feet (60 inches) with 5 sec timeout */
    routine->AddCommands(frc2::ParallelRaceGroup(DriveDistanceCommand(-60), DelayMillisecondsCommand(5000)));
    return routine;
}

frc2::Command* Autonomous::ShootPreload() {
    frc2::SequentialCommandGroup* routine = new frc2::SequentialCommandGroup();

    /* Ramp up shooter for 1 second */
    routine->AddCommands(frc2::ParallelRaceGroup(RunShooterAutoCommand(), DelayMillisecondsCommand(3500)));
    /* Run belts and shooter (3 seconds timeout) */
    routine->AddCommands(frc2::ParallelRaceGroup(RunAllBeltsCommand(), RunShooterVelocityCommand(), DelayMillisecondsCommand(4000)));
    /* Drive backwards 10 feet (120 inches) with 5 sec timeout */
    routine->AddCommands(frc2::ParallelRaceGroup(DriveDistanceCommand(-140)));
    return routine;
}

/** @brief Autonmous routine to pick up a second ball and shoot the preloads. Start facing the second ball. 
 * @return void
*/
frc2::Command* Autonomous::TwoBallAuto() {
    frc2::SequentialCommandGroup* routine = new frc2::SequentialCommandGroup();

    // Put the intake out

    // Drive toward the second ball to pick it up

    // Stop driving.

    // Pull the intake in

    // Do a 180

    // Drive towards the goal

    // Stop driving once lined up

    // Run the shooter to shoot the balls

    // Stop the shooter

    // Drive backwards away from the goal

    // Stop driving

    // Do a 180

    return routine;
}