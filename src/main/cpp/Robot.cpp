/**
 * @file Robot.cpp
 * @date 1/13/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Central source code for the Robot.
**/

#include <frc/Joystick.h>
#include <frc/TimedRobot.h>
#include <frc/drive/DifferentialDrive.h>
#include "frc/Controller/RamseteController.h"
#include <frc/motorcontrol/PWMSparkMax.h>
#include "rev/CANSparkMax.h"
#include "../include/RobotMap.h"

/** This is the central robot class. */
class Robot : public frc::TimedRobot {

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

 public:
 /** 
  * @brief This function is run when the Robot is initialized.
  * @return void
  */
  void RobotInit() override {

  }

  /** 
   * @brief This function is run when teleoperated mode is initialized.
   * @return void
   */
  void TeleopInit() override {
    /** Set the Motor Controllers in Coast Mode */
    leftLeader.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
    leftFollower1.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
    leftFollower2.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);

    rightLeader.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
    rightFollower1.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
    rightFollower2.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
  }

  /** 
   * @brief This function is run periodically in the teleoperated mode.
   * @return void
   */
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
