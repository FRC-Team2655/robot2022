/**
 * @file Autonomous.cpp
 * @date 2/23/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Source code for the Autonomous routines.
**/

#include "Autonomous.h"

#include "Robot.h"

/** The constructor for the Autonomous class */
Autonomous::Autonomous() {}

/** @brief Autonomous routine to drive backwards off the tarmac line and do a 180. Start with front bumper lined up with tarmac line.
 * @return The autonomous routine as a sequential command group
 */ 
frc2::Command* Autonomous::DriveForwardOffTarmac() {
    /* Creating the routine as a sequential command group */
    frc2::SequentialCommandGroup* routine = new frc2::SequentialCommandGroup();

    /* Drive forward 50 inches */
    routine->AddCommands(DriveDistanceCommand(50));

    // Return the routine
    return routine;
}

/** @brief Autonomous routine to shoot the preload and drive off the tarmac line. Start pressed up against the goal.
 * @return The autonomous routine as a sequential command group
 */ 
frc2::Command* Autonomous::ShootPreloadAndDrive() {
    // Creating the routine as a sequential command group
    frc2::SequentialCommandGroup* routine = new frc2::SequentialCommandGroup();

    /* Ramp up shooter with 3.5 sec timeout */
    routine->AddCommands(frc2::ParallelRaceGroup(RunShooterAutoCommand(), DelayMillisecondsCommand(3500)));
    routine->AddCommands(DelayMillisecondsCommand(1000));
    /* Run belts and shooter (4 seconds timeout) */
    routine->AddCommands(frc2::ParallelRaceGroup(RunAllBeltsCommand(), RunShooterVelocityCommand(), DelayMillisecondsCommand(4000)));
    /* Drive backwards 140 inches */
    routine->AddCommands(frc2::ParallelRaceGroup(DriveDistanceCommand(-140)));
    /* Do a 180 */
    routine->AddCommands(RotateDegreesCommand(180));
    // Return the routine.
    return routine;
}

/** @brief Autonmous routine to pick up a second ball, shoot the preloads, and drive off the tarmac line. Start with front bumper lined up with tarmac line facing the second ball. 
 * @return The autonomous routine as a sequential command group
*/
frc2::Command* Autonomous::TwoBallAuto() {
    // Create the routine as a sequential command group.
    frc2::SequentialCommandGroup* routine = new frc2::SequentialCommandGroup();

    // Put the intake out
    routine->AddCommands(IntakeOutCommand());

    // Wait for intake to be fully out
    routine->AddCommands(DelayMillisecondsCommand(1000));

    // Drive toward the second ball to pick it up
    routine->AddCommands(frc2::ParallelRaceGroup(DriveDistanceCommand(50), RunIntakeRollersCommand(), RunBeltsCommand()));

    // Pull the intake in
    routine->AddCommands(IntakeInCommand());

    // Drive backwards (50 inches) and rotate 155 degrees (approximately toward goal)
    routine->AddCommands(DriveDistanceCommand(-50));
    routine->AddCommands(RotateDegreesCommand(-155));

    // Drive towards the goal (90 inches)
    routine->AddCommands(DriveDistanceCommand(90), DelayMillisecondsCommand(1500));

    // Ramp the shooter (2 sec timeout) and shoot the balls (3 sec timeout)
    routine->AddCommands(frc2::ParallelRaceGroup(RunShooterAutoCommand(), DelayMillisecondsCommand(1000)));
    routine->AddCommands(DelayMillisecondsCommand(500));
    routine->AddCommands(frc2::ParallelRaceGroup(RunAllBeltsCommand(), RunShooterVelocityCommand(), RunIntakeRollersCommand(), DelayMillisecondsCommand(3500)));

    // Drive backwards (140 inches) away from the goal
    routine->AddCommands(DriveDistanceCommand(-140));

    // Do a 180
    routine->AddCommands(RotateDegreesCommand(180));

    // Return the routine.
    return routine;
}

/** @brief Function to rotate the robot a certain amount of degrees for testing purposes.
 * @return The autonomous routine as a sequential command group.
 */ 
frc2::Command* Autonomous::RotateDegreesTest() {
    // Creating the autonomous routine as a sequential command group
    frc2::SequentialCommandGroup* routine = new frc2::SequentialCommandGroup();
    // Rotate 90 one direction
    routine->AddCommands(RotateDegreesCommand(-155));

    //routine->AddCommands(DelayMillisecondsCommand(1000));
    // Rotate 90 the other direction
    //routine->AddCommands(RotateDegreesCommand(-90));

    // Return the autonomous routine as a sequential command group
    return routine;
}

frc2::Command* Autonomous::ThreeBallAuto() {
    // Creating the autonomous routine as a sequential command group
    frc2::SequentialCommandGroup* routine = new frc2::SequentialCommandGroup();

    // Record current gyro angle (pressed up against the goal)
    double initialGyroAngle = Robot::driveBase.GetIMUAngle();

    // Ramp up wheel
    routine->AddCommands(RunShooterAutoCommand());

    // Run belts and shooter to shoot ball
    routine->AddCommands(frc2::ParallelRaceGroup(RunBeltsCommand(), RunShooterVelocityCommand(), DelayMillisecondsCommand(3000)));

    // Drive backwards 116.17 inches plus half the length of the robot
    routine->AddCommands(DriveDistanceCommand(116.17 + 14.00));

    // Rotate to left 90 degrees

    // Put intake out

    // Drive forwards ___ inches running intake rollers and automatic serialization

    // Pull intake in

    // Rotate to right 180 degrees

    // Put intake out

    // Drive forwards ___ inches running intake rollers and automatic serialization

    // Drive backwards ___ inches to initial point lined up with goal

    // Rotate to the recorded starting angle

    // Drive forwards into goal

    // Ramp up shooter

    // Run belts and shooter wheel to shoot balls

    return routine;
}