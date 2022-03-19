/**
 * @file DriveDistanceCommand.h
 * @date 3/17/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Declaring the DriveDistanceCommand class.
**/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

/** This is the command to drive the robot a given distance in inches*/
class DriveDistanceCommand
    : public frc2::CommandHelper<frc2::CommandBase, DriveDistanceCommand> {
 public:
  //DriveDistanceCommand(double distance, double maxSpeed);
  DriveDistanceCommand(double distance);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

  /* P term for P feedback loop from encoders */
  double P_encoders = 100.0;

  /* P term for P feedback loop from gyro for angle correction */
  double P_gyro = 85.0;

  /* Angle read from current axis of interest on the gyro */
  double gyroAngle;

  /* max speed during movement. In units of motor RPM (0 - 5800) */
  double maxSpeed;

private:

  double GetCurrentDistance();

  /* Initial starting angle from gyro */
  double gyroStartAngle;
  /* Target distance to travel in inches*/
  double distance;
  /* Current distance travelled  in inches*/
  double currentDistance;
  /* Current "uncompensated" speed */
  double currentSpeed;
  /* min speed during movement. In units of motor RPM (0 - 5800) */
  double minSpeed = 1000;
  /* Amount to step up speed per iteration when accelerating */
  double speedStep = 85;
  /* distance to start ramp down PID (inches) */
  double rampDownDistance = 36.0;
  /* travel direction */
  bool goingForward;
};
