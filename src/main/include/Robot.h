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
#include "RobotMap.h"
#include <ctre/Phoenix.h>
#include "Input.h"
#include "Subsystems/LimelightSubsystem.h"
#include <frc2/command/CommandScheduler.h>

#include "rev/ColorSensorV3.h"
#include "rev/ColorMatch.h"

/** The Robot class is the central class in the project. */
class Robot : public frc::TimedRobot {
public:
  static DriveBaseSubsystem driveBase;
  static Input input;
  static LimelightSubsystem limelight;
  static BeltSubsystem belts;
  static IntakeSubsystem intake;
  static ShooterSubsystem shooter;

  void RobotInit() override;
  void RobotPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
private:
};