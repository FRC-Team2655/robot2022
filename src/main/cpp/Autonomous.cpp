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
    routine->AddCommands(DriveDistanceCommand(50));

    routine->AddCommands(RunShooterVelocityCommand());

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
    /* Do a 180 */
    routine->AddCommands(RotateDegreesCommand(180));
    return routine;
    
}

/** @brief Autonmous routine to pick up a second ball and shoot the preloads. Start facing the second ball. 
 * @return void
*/
frc2::Command* Autonomous::TwoBallAuto() {
    frc2::SequentialCommandGroup* routine = new frc2::SequentialCommandGroup();

    // Put the intake out
    routine->AddCommands(IntakeOutCommand());

    // Drive toward the second ball to pick it up
    routine->AddCommands(frc2::ParallelRaceGroup(DriveDistanceCommand(50), RunIntakeRollersCommand(), RunBeltsCommand()));

    // Pull the intake in
    routine->AddCommands(IntakeInCommand());

    // Do a 180
    routine->AddCommands(DriveDistanceCommand(-50));
    routine->AddCommands(RotateDegreesCommand(-155));

    // Drive towards the goal
    routine->AddCommands(DriveDistanceCommand(90));

    // Run the shooter to shoot the balls
    routine->AddCommands(frc2::ParallelRaceGroup(RunShooterAutoCommand(), DelayMillisecondsCommand(2000)));
    routine->AddCommands(frc2::ParallelRaceGroup(RunShooterVelocityCommand(), RunAllBeltsCommand(), DelayMillisecondsCommand(3000)));

    // Drive backwards away from the goal
    routine->AddCommands(DriveDistanceCommand(-140));

    // Do a 180
    routine->AddCommands(RotateDegreesCommand(180));

    return routine;
}

frc2::Command* Autonomous::RotateDegreesTest() {
    frc2::SequentialCommandGroup* routine = new frc2::SequentialCommandGroup();

    routine->AddCommands(RotateDegreesCommand(90));

    routine->AddCommands(RotateDegreesCommand(-90));

    return routine;
}