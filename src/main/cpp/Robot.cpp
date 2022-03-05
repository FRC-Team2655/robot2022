/**
 * @file Robot.cpp
 * @date 1/13/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Central source code for the Robot.
**/

#include "Robot.h"

/** Declaring the DriveBaseSubsystem instance. */
DriveBaseSubsystem Robot::driveBase;
/** Declaring the Input instance. */
Input Robot::input;
/** Declaring the Limelight instance */
LimelightSubsystem Robot::limelight;
/** Declaring the Belts instance */
BeltSubsystem Robot::belts;
/** Declaring the Intake instance */
IntakeSubsystem Robot::intake;
/** Declaring the Shooter instance. */
ShooterSubsystem Robot::shooter;

/**
 * @brief This function is run when the Robot is Initialized.
 * @return void
 */ 
void Robot::RobotInit() {
  frc::SmartDashboard::PutNumber("IMU Angle", 0);
}

/**
 * @brief This function is run periodically while the Robot is initialized.
 * @return void
 */ 
void Robot::RobotPeriodic() {
  frc::SmartDashboard::PutNumber("IMU Angle", driveBase.GetIMUAngle());

  limelight.UpdateValues();
  limelight.PrintValues(); 

  frc2::CommandScheduler::GetInstance().Run();
}

/**
 * @brief This function is run when the autonomous mode has been initialized.
 * @return void
 */ 
void Robot::AutonomousInit() {
  driveBase.ResetIMUAngle();
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
   driveBase.SetCoastMode();
 }

/** 
  * @brief This function is run periodically in the teleoperated mode.
  * @return void
  */
void Robot::TeleopPeriodic() {
  /** Logic to track whether the shooter is running and whether the shooter is at its maximum velocity */
  if (shooter.GetShooterVelocity() <= 1.0) {
    isShooterAtMax = false;
    isShooterRunning = false;
  }else if ((shooter.GetShooterVelocity() < SHOOTERVELOCITY) && (shooter.GetShooterVelocity() > 0.0)) {
    isShooterAtMax = false;
    isShooterRunning = true;
  }else if (shooter.GetShooterVelocity() >= SHOOTERVELOCITY) {
    isShooterAtMax = true;
    isShooterRunning = true;
  }

  /** Logic to control the LED colors when shooting. Red and blue corresponding to the detected ball by the color sensor. 
   * Strobe = shooter ramping up. Solid = up to speed. Dual color = shooter not running.
   */ 
  if (isShooterRunning) {
    if (!isShooterAtMax) {
      if (belts.GetDetectedColor() == "Blue") {
        LEDController.Set(STROBEBLUE);
      }else if (belts.GetDetectedColor() == "Red") {
        LEDController.Set(STROBERED);
      }
    }else{
      if (belts.GetDetectedColor() == "Blue") {
        LEDController.Set(SOLIDRED);
      }else if (belts.GetDetectedColor() == "Red") {
        LEDController.Set(SOLIDBLUE);
      }
    }
  }else{
    LEDController.Set(DUALCOLOR);
  }
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
