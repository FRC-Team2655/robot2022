/**
 * @file RobotMap.h
 * @date 1/13/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief RobotMap is used to define all the variables used throughout the Robot Program 
**/


#include <frc/DoubleSolenoid.h>


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

/** Climber ID for the left climber  */
#define LEFTCLIMBERID 5
/** CLimber ID for the right climber */
#define RIGHTCLIMBERID 6



/** PID Value Definitions */

/** P value for the shooter */
#define KPSHOOTER 0.0001
/** I value for the shooter */
#define KISHOOTER 0
/** D value for the shooter */
#define KDSHOOTER 0
/** FeedForward value for the shooter */
#define KFFSHOOTER 0

/** P value for the right climber */
#define KPRIGHTCLIMBER 0.015
/** I value for the right climber */
#define KIRIGHTCLIMBER 0
/** D value for the right climber */
#define KDRIGHTCLIMBER 0
/** FeedForward value for the right climber */
#define KFFRIGHTCLIMBER 1/150
/** P value for the left climber */
#define KPLEFTCLIMBER 0.015
/** I value for the left climber */
#define KILEFTCLIMBER 0
/** D value for the left climber */
#define KDLEFTCLIMBER 0
/** FeedForward value for the left climber */
#define KFFLEFTCLIMBER 1/150



/** Velocities */

/** Right side drivetrain max velocity */
#define RMAXVELOCITY 5700

/** Left side drivetrain max velocity */
#define LMAXVELOCITY 5700

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

/** The speed to test the climber at (moving up and down) */
#define CLIMBERTESTINGSPEED 0.1



/** Solenoid Ports */

/** Intake Solenoid 1 Forward Port */
#define INTAKELEFTSOLFORWARDPORT 0

/** Intake Solenoid 1 Reverse Port */
#define INTAKELEFTSOLREVERSEPORT 1

/** Intake Solenoid 2 Forward Port */
#define INTAKERIGHTSOLFORWARDPORT 14

/** Intake Solenoid 2 Reverse Port */
#define INTAKERIGHTSOLREVERSEPORT 15



/** Solenoid directions */
#define LEFTSOLIN frc::DoubleSolenoid::kReverse
#define LEFTSOLOUT frc::DoubleSolenoid::kForward
#define RIGHTSOLIN frc::DoubleSolenoid::kReverse
#define RIGHTSOLOUT frc::DoubleSolenoid::kForward



/** PWM Ports */

/** The LED PWM Port */
#define LEDPWMPORT 0



/** DIO Ports */

/** The Proximity Sensor DIO Port */
#define PROXIMITYSENSORPORT 1



/** LED Color codes (Referencing Blinkin manual pg. 14) */
#define STROBERED -0.11
#define STROBEBLUE -0.09
#define SOLIDRED 0.61
#define SOLIDBLUE 0.87
#define DUALCOLOR 0.53
#define RAINBOW -0.43



/** How close the ball has to be to the color sensor for it to be considered "triggered" */
#define COLORSENSORPROXIMITYDISTANCE 10


/** The maximum height of the climber in terms of encoder rotations. */
#define CLIMBERMAXHEIGHT 160