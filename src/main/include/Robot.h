/**
 * @file Robot.h
 * @date 1/13/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Defines the Robot class.
**/

#pragma once

#include <frc/TimedRobot.h>
#include "rev/CANSparkMax.h"
#include <frc/Joystick.h>
#include <frc/drive/DifferentialDrive.h>
#include "frc/Controller/RamseteController.h"
#include <frc/motorcontrol/PWMSparkMax.h>
#include "RobotMap.h"

/** The Robot class is the central class in the project. */
class Robot : public frc::TimedRobot {
public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
private:
  /** Definition for the left leader motor controller on the drivetrain. */
  rev::CANSparkMax leftLeader {LEFTLEADERID, rev::CANSparkMax::MotorType::kBrushless};
  /** Definition for the first left follower motor controller on the drivetrain. */
  rev::CANSparkMax leftFollower1 {LEFTFOLLOWER1ID, rev::CANSparkMax::MotorType::kBrushless};
  /** Definition for the second left follower motor controller on the drivetrain. */
  rev::CANSparkMax leftFollower2 {LEFTFOLLOWER2ID, rev::CANSparkMax::MotorType::kBrushless};

  /** Definition for the right leader motor controller on the drivetrain. */
  rev::CANSparkMax rightLeader {RIGHTLEADERID, rev::CANSparkMax::MotorType::kBrushless};
  /** Definition for the first right follower motor controller on the drivetrain. */
  rev::CANSparkMax rightFollower1 {RIGHTFOLLOWER1ID, rev::CANSparkMax::MotorType::kBrushless};
  /** Definition for the second right follower motor controller on the drivetrain. */
  rev::CANSparkMax rightFollower2 {RIGHTFOLLOWER2ID, rev::CANSparkMax::MotorType::kBrushless};

  /** Assigning the motor controllers to the DifferentialDrive */
  frc::DifferentialDrive robotDrive{leftLeader, rightLeader};

  /** Defining the Joystick */
  frc::Joystick joystick {0};

  /** Create the Ramsete Controller */
  frc::RamseteController rController;
};