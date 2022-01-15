/**
 * @file Robot.h
 * @date 1/13/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Defines the Robot class.
**/

#pragma once

#include <frc/TimedRobot.h>
#include "frc/Controller/RamseteController.h"
#include <frc/motorcontrol/PWMSparkMax.h>
#include "Subsystems/DriveBaseSubsystem.h"
#include "RobotMap.h"
#include <ctre/Phoenix.h>
#include "Input.h"

/** The Robot class is the central class in the project. */
class Robot : public frc::TimedRobot {
public:
  static DriveBaseSubsystem driveBase;
  static Input input;

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