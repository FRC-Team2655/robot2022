/**
 * @file Robot.h
 * @date 1/13/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Defines the Robot class.
**/

#pragma once

#include <frc/smartdashboard/SmartDashboard.h>

#include <frc/TimedRobot.h>
#include "frc/Controller/RamseteController.h"
#include <frc/motorcontrol/PWMSparkMax.h>
#include "Subsystems/DriveBaseSubsystem.h"
#include "Subsystems/BeltSubsystem.h"
#include "Subsystems/IntakeSubsystem.h"
#include "Subsystems/ShooterSubsystem.h"
#include "Subsystems/ClimbSubsystem.h"
#include "RobotMap.h"
#include <ctre/Phoenix.h>
#include "Input.h"
#include "Subsystems/LimelightSubsystem.h"
#include <frc2/command/CommandScheduler.h>

#include "rev/ColorSensorV3.h"
#include "rev/ColorMatch.h"

#include <frc/motorcontrol/Spark.h>
#include <frc/smartdashboard/SendableChooser.h>

#include <pathplanner/lib/PathPlanner.h>

#include "Autonomous.h"

/** The Robot class is the central class in the project. */
class Robot : public frc::TimedRobot {
public:
  static DriveBaseSubsystem driveBase;
  static Input input;
  static LimelightSubsystem limelight;
  static BeltSubsystem belts;
  static IntakeSubsystem intake;
  static ShooterSubsystem shooter;
  static ClimbSubsystem climber;
  static Autonomous auton;

  void RobotInit() override;
  void RobotPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
private:

  // This will load the file "Example Path.path" and generate it with a max velocity of 8 m/s and a max acceleration of 5 m/s^2
  pathplanner::PathPlannerTrajectory examplePath = pathplanner::PathPlanner::loadPath("New Path", 8_mps, 5_mps_sq);

  // Sample the state of the path at 1.2 seconds
  pathplanner::PathPlannerTrajectory::PathPlannerState exampleState = examplePath.sample(1.2_s);

  /** Declaring the controller for the LED via PWM */
  //frc::Spark LEDController {LEDPWMPORT};

  // Creating the list of autonomous routines as a sendable chooser for the dash
  frc::SendableChooser<int> autoChooser;

  // The autonomous command to be assigned to a specific routine
  frc2::Command* autonomousCommand = nullptr;
};