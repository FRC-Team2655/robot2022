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
/** Declaring the climber instance */
ClimbSubsystem Robot::climber;

Autonomous Robot::auton;

/**
 * @brief This function is run when the Robot is Initialized.
 * @return void
 */ 
void Robot::RobotInit() {

  // Putting the IMU Angle onto smartdashboard.
  frc::SmartDashboard::PutNumber("IMU Angle", 0);

  frc::SmartDashboard::PutNumber("Shooter Velocity", 0);

  frc::SmartDashboard::PutBoolean("Shooter up to speed", 0);

  // Setting (most) of the motor controllers into coast mode.
  belts.SetBeltsCoastMode();
  intake.SetIntakeRollersCoastMode();
  shooter.SetShooterCoastMode();

  // Put the climber in brake mode
  climber.SetClimberBrakeMode();

  // Reset the climber in the down position (we are assuming the robot starts every match with the climber in the down position.)
  climber.ResetClimberDown();
}

/**
 * @brief This function is run periodically while the Robot is initialized.
 * @return void
 */ 
void Robot::RobotPeriodic() {
  // Updating the IMU Angle on smartdashboard
  frc::SmartDashboard::PutNumber("IMU Angle", driveBase.GetIMUAngle());
  // Updatin the Shooter Velocity on smartdashboard
  frc::SmartDashboard::PutNumber("Shooter Velocity", shooter.GetShooterVelocity());

  // Update the limelight values
  //limelight.UpdateValues();

  // Update the command scheduler periodically, VERY IMPORTANT! Commands will not run otherwise.
  frc2::CommandScheduler::GetInstance().Run();
}

/**
 * @brief This function is run when the autonomous mode has been initialized.
 * @return void
 */ 
void Robot::AutonomousInit() {
  // Reset the IMU Angle at the beginning of auto
  driveBase.ResetIMUAngle();

  autonomousCommand = auton.ShootPreload();
  autonomousCommand->Schedule();
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
   // Set drive base motor controllers into coast mode.
   driveBase.SetCoastMode();

   // Setting a default direction for the intake (in) at the start of the match
   intake.IntakeIn();
 }

/** 
  * @brief This function is run periodically in the teleoperated mode.
  * @return void
  */
void Robot::TeleopPeriodic() {
  /** Logic to track whether the shooter is running and whether the shooter is at its maximum velocity */
  if (shooter.GetShooterVelocity() <= 0.0) {
    isShooterAtMax = false;
    isShooterRunning = false;
  }else if ((shooter.GetShooterVelocity() < SHOOTERVELOCITY) && (shooter.GetShooterVelocity() > 0.0)) {
    isShooterAtMax = false;
    isShooterRunning = true;
  }else if (shooter.GetShooterVelocity() >= SHOOTERVELOCITY) {
    isShooterAtMax = true;
    isShooterRunning = true;
  }

  frc::SmartDashboard::PutBoolean("Shooter up to speed", isShooterAtMax);

  /** Logic to control the LED colors when shooting. Red and blue corresponding to the detected ball by the color sensor. 
   * Strobe = shooter ramping up. Solid = up to speed. Dual color = shooter not running.
   */ 
  /*if (isShooterRunning) {
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
    LEDController.Set(RAINBOW);
  }*/
}

/**
 * @brief This function is run when the Robot is initially disabled.
 * @return void
 */ 
void Robot::DisabledInit() {
  // Put the drive base motor controllers in brake mode.
  driveBase.SetBrakeMode();
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
