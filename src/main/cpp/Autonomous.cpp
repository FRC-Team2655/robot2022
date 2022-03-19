/**
 * @file Autonomous.cpp
 * @date 2/23/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Source code for the Autonomous routines.
**/

#include "Autonomous.h"

/** The constructor for the Autonomous class */
Autonomous::Autonomous() {}

/** @brief Autonomous routine to shoot the preload and drive away from the goal. Start lined up with the goal. 
 * @return void
*/
frc2::Command* Autonomous::ShootPreload() {
    frc2::SequentialCommandGroup* routine = new frc2::SequentialCommandGroup();

    // Run shooter to shoot preload.
    routine->AddCommands(frc2::ParallelRaceGroup(RunShooterVelocityCommand(), DelayMillisecondsCommand(3000)));

    routine->AddCommands(frc2::ParallelRaceGroup(RunAllBeltsCommand(), DelayMillisecondsCommand(3000)));

    // Drive backwards away from the goal and off the tarmac line
    routine->AddCommands(DriveDistanceCommand(-130));

    // Rotate 90 to face next ball
    routine->AddCommands(RotateDegreesCommand(-90));
}

/** @brief Autonmous routine to pick up a second ball and shoot the preloads. Start facing the second ball. 
 * @return void
*/
frc2::Command* Autonomous::TwoBallAuto() {
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
}