/**
 * @file Robot.cpp
 * @date 1/13/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Central source code for the Robot.
**/

#include "Robot.h"

/**
 * @brief This function is run when the Robot is Initialized.
 * @return void
 */ 
void Robot::RobotInit() {

}

/**
 * @brief This function is run periodically while the Robot is initialized.
 * @return void
 */ 
void Robot::RobotPeriodic() {

}

/**
 * @brief This function is run when the autonomous mode has been initialized.
 * @return void
 */ 
void Robot::AutonomousInit() {

}

/**
 * @brief This function is run periodically in the autonomous mode.
 * @return void
 */ 
void Robot::AutonomousPeriodic() {

}

 /** 
  * @brief This function is run when teleoperated mode is initialized.
  * @return void
  */
 void Robot::TeleopInit() {
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
void Robot::TeleopPeriodic() {
   // Drive with arcade style
   robotDrive.ArcadeDrive(joystick.GetY(), joystick.GetZ());
}

/**
 * @brief This function is run when the Robot is initially disabled.
 * @return void
 */ 
void Robot::DisabledInit() {

}

/**
 * @brief This function is run periodically while the robot is disabled.
 * @return void
 */ 
void Robot::DisabledPeriodic() {

}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
