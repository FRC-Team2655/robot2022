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
  DriveDistanceCommand(double distance);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

  /* P term for P feedback loop from encoders */
  double P_encoders = 0.05;

  /* P term for P feedback loop from gyro for angle correction */
  double P_gyro = 0.045;

  /* Angle read from current axis of interest on the gyro */
  double gyroAngle;

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
  /* min speed during movement. In units of power (0 - 1) */
  double minSpeed = 0.3;
  /* max speed during movement. In units of power (0 - 1) */
  double maxSpeed = 0.5;
  /* Amount to step up speed per iteration when accelerating */
  double speedStep = 0.02;
  /* distance to start ramp down PID (inches) */
  double rampDownDistance = 36.0;
  /* travel direction */
  bool goingForward;
};
