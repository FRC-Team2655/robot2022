// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <frc/Joystick.h>
#include <frc/TimedRobot.h>
#include <frc/drive/DifferentialDrive.h>
#include "frc/Controller/RamseteController.h"
#include <frc/motorcontrol/PWMSparkMax.h>
#include "rev/CANSparkMax.h"
#include "../include/RobotMap.h"


/**
 * This is a demo program showing the use of the DifferentialDrive class.
 * Runs the motors with arcade steering.
 */
class Robot : public frc::TimedRobot {

  /* Declaring Motor Controllers */
  rev::CANSparkMax leftLeader {LEFTLEADERID, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax leftFollower1 {LEFTFOLLOWER1ID, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax leftFollower2 {LEFTFOLLOWER2ID, rev::CANSparkMax::MotorType::kBrushless};
  

  rev::CANSparkMax rightLeader {RIGHTLEADERID, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax rightFollower1 {RIGHTFOLLOWER1ID, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax rightFollower2 {RIGHTFOLLOWER2ID, rev::CANSparkMax::MotorType::kBrushless};

  /* Assigning the motor controllers to the DifferentialDrive */
  frc::DifferentialDrive robotDrive{leftLeader, rightLeader};

  /* Defining the Joystick */
  frc::Joystick joystick {0};

  /* Create the Ramsete Controller */
  frc::RamseteController rController;

 public:
  void RobotInit() override {

  }

  void TeleopInit() override {
    /* Set the Motor Controllers in Coast Mode */
    leftLeader.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
    leftFollower1.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
    leftFollower2.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);

    rightLeader.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
    rightFollower1.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
    rightFollower2.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
  }

  void TeleopPeriodic() override {
    // Drive with arcade style
    robotDrive.ArcadeDrive(joystick.GetY(), joystick.GetZ());
  }
};

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
