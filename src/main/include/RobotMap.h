/**
 * @file RobotMap.h
 * @date 1/13/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief RobotMap is used to define all the variables used throughout the Robot Program 
**/

/** Motor Controller ID Definitions */

/** Motor ID for the left leader motor controller on drivetrain */
#define LEFTLEADERID 6
/** Motor ID for the first left follower motor controller on drivetrain */
#define LEFTFOLLOWER1ID 5
/** Motor ID for the second left follower motor controller on drivetrain */
#define LEFTFOLLOWER2ID 4

/** Motor ID for the right leader motor controller on drivetrain */
#define RIGHTLEADERID 1
/** Motor ID for the first right follower motor controller on drivetrain */
#define RIGHTFOLLOWER1ID 2
/** Motor ID for the second right follower motor controller on drivetrain */
#define RIGHTFOLLOWER2ID 3

/** Motor ID for the Intake */
#define INTAKEID 9

/** Solenoid ID for the Intake */
#define INTAKESOLA 5
/** Second Solenoid ID for the Intake */
#define INTAKESOLB 6



/** PID Value Definitions */

/** Left side drivetrain P value */
#define KPLEFT 0.1
/** Left side drivetrain I value */
#define KILEFT 0.1

/** Right side drivetrain P value */
#define KPRIGHT 0.0001
/** Right side drivetrain I value */
#define KIRIGHT 0.0001



/** Max Velocities */

/** Right side drivetrain max velocity */
#define RMAXVELOCITY 5500

/** Left side drivetrain max velocity */
#define LMAXVELOCITY 5500

/** Intake percentage speed */
#define INTAKESPEED 0.8

