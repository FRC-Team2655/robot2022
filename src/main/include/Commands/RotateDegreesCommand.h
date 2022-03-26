/**
 * @file RotateDegreesCommand.h
 * @date 3/17/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Declaring the RotateDegreesCommand class.
**/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

/** This command will rotate the robot through a given amount of degrees */
class RotateDegreesCommand
    : public frc2::CommandHelper<frc2::CommandBase, RotateDegreesCommand> {
 public:
  RotateDegreesCommand(double degrees);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

  /* Maximum speed to run at while turning (motor perent) */
  double maxSpeed = 1.0;
  /* Minimum speed to run while turning (motor percent) */
  double minSpeed = 0.50;
  /* delta from target angle at which to start ramp down (degrees) */
  double rampdownStartAngle = 15;
  /* P term for gyro feedback while ramping down */
  double P_gyro = 0.09;
  /* ramp up increment */
  double rampUpIncrement = 0.01;
  /* degrees to turn by */
  double degrees;
private:
  /* Start angle for the robot */
  double startAngle;
  /*Target angle to reach*/
  double targetAngle;
  /* Track if need to turn right or not */
  bool turnRight;
  /* current robot angle */
  double currentAngle;
  /* Current motor speed (RPM) */
  double currentSpeed;
};
