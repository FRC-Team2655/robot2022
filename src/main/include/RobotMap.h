/**
 * @file RobotMap.h
 * @date 1/13/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief RobotMap is used to define all the variables used throughout the Robot Program 
**/


#include <frc/DoubleSolenoid.h>






/** Motor Controller ID Definitions */

/** Motor ID for the left leader motor controller on drivetrain */
#define LEFTLEADERID 1
/** Motor ID for the first left follower motor controller on drivetrain */
#define LEFTFOLLOWER1ID 2
/** Motor ID for the second left follower motor controller on drivetrain */
#define LEFTFOLLOWER2ID 3

/** Motor ID for the right leader motor controller on drivetrain */
#define RIGHTLEADERID 4
/** Motor ID for the first right follower motor controller on drivetrain */
#define RIGHTFOLLOWER1ID 6
/** Motor ID for the second right follower motor controller on drivetrain */
#define RIGHTFOLLOWER2ID 11

/** Motor ID for the right belt motor controller */
#define RIGHTBELTID 9
/** Motor ID for the left belt motor controller */
#define LEFTBELTID 8

/** For the first shooter motor controller. Left side shooter motor controller. */
#define SHOOTER1 15
/** For the second shooter motor controller. Right side shooter motor controller. */
#define SHOOTER2 16

/** Motor ID for the Intake */
#define INTAKEROLLERSID 10

/** Climber ID for the left climber  */
#define LEFTCLIMBERID 12
/** CLimber ID for the right climber */
#define RIGHTCLIMBERID 5

/** ID for the shooter kicker */
#define SHOOTERKICKERID 7



/** PID Value Definitions */

/** P value for the shooter */
#define KPSHOOTER 0.00005
/** I value for the shooter */
#define KISHOOTER 0.0
/** D value for the shooter */
#define KDSHOOTER 0.0
/** FeedForward value for the shooter */
#define KFFSHOOTER 0.0001805
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
#define INTAKEROLLERSSPEED 0.75

/** Speed to run the belt */
#define BELTSPEED 0.2

/** Speed to run shootor motor controllers */
#define SHOOTERPERCENTAGE 0.8
 
/** Shooter max velocity */
#define SHOOTERVELOCITY 3600

/** Speed for the shooter to run at a very slow speed such that the ball "drips" out. */
#define SHOOTERDRIPOUTSPEED 900

/** The speed to test the climber at (moving up and down) */
#define CLIMBERTESTINGSPEED 0.10

/** The speed to climb with */
#define CLIMBINGSPEED 0.60

/** Speed for the shooter kicker */
#define SHOOTERKICKERSPEED -0.25



/** Solenoid Ports */

/** Intake Left Solenoid Forward Port */
#define INTAKELEFTSOLFORWARDPORT 6

/** Intake Left Solenoid Reverse Port */
#define INTAKELEFTSOLREVERSEPORT 9

/** Intake Right Solenoid Forward Port */
#define INTAKERIGHTSOLFORWARDPORT 7

/** Intake Right Solenoid Reverse Port */
#define INTAKERIGHTSOLREVERSEPORT 8



/** Solenoid directions */
#define LEFTSOLIN frc::DoubleSolenoid::kForward
#define LEFTSOLOUT frc::DoubleSolenoid::kReverse
#define RIGHTSOLIN frc::DoubleSolenoid::kForward
#define RIGHTSOLOUT frc::DoubleSolenoid::kReverse



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
#define CLIMBERMAXHEIGHT 153