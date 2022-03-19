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

  /** Declaring the controller for the LED via PWM */
  //frc::Spark LEDController {LEDPWMPORT};

  frc2::Command* autonomousCommand = nullptr;

  /** A boolean to track whether the shooter is at maximum velocity. True is at max, false is not. */
  bool isShooterAtMax = false;
  /** A boolean to track whether the shooter is running. True is running, false is not. */
  bool isShooterRunning = false;
};