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

/** Motor ID for the lower left belt motor controller */
#define LOWERBELT1ID 10
/** Motor ID for the lower right belt motor controller */
#define LOWERBELT2ID 11
/** Motor ID for the upper left belt motor controller */
#define UPPERBELT1ID 12
/** Motor ID for the upper right belt motor controller */
#define UPPERBELT2ID 13

/** For the first shooter motor controller */
#define SHOOTER1 12
/** For the second shooter motor controller */
#define SHOOTER2 13

/** Motor ID for the Intake */
#define INTAKEROLLERSID 9

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

/** P value for the shooter */
#define KPSHOOTER 0.0001
/** I value for the shooter */
#define KISHOOTER 0
/** D value for the shooter */
#define KDSHOOTER 0

/** FeedForward value for the shooter */
#define KFFSHOOTER 0



/** Velocities */

/** Right side drivetrain max velocity */
#define RMAXVELOCITY 5500

/** Left side drivetrain max velocity */
#define LMAXVELOCITY 5500

/** Intake rollers percentage speed */
#define INTAKEROLLERSSPEED 0.8

/** Speed to run the belt */
#define BELTSPEED 0.7

/** Speed to run shootor motor controllers */
#define SHOOTERPERCENTAGE 0.8
 
/** Shooter max velocity */
#define SHOOTERVELOCITY 5000

/** Speed for the shooter to run at a very slow speed such that the ball "drips" out. */
#define SHOOTERDRIPOUTSPEED 500



/** Solenoid Ports */

/** Intake Solenoid 1 Forward Port */
#define INTAKESOL1FORWARDPORT 0

/** Intake Solenoid 1 Reverse Port */
#define INTAKESOL1REVERSEPORT 1

/** Intake Solenoid 2 Forward Port */
#define INTAKESOL2FORWARDPORT 14

/** Intake Solenoid 2 Reverse Port */
#define INTAKESOL2REVERSEPORT 15



/** PWM Ports */

/** The LED PWM Port */
#define LEDPWMPORT 0



/** DIO Ports */

/** The Proximity Sensor DIO Port */
#define PROXIMITYSENSORPORT 1



/** How close the ball has to be to the color sensor for it to be considered "triggered" */
#define COLORSENSORPROXIMITYDISTANCE 10