/**
 * @file RotateToGyroAngleCommand.h
 * @date 3/17/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Declaring the RotateToGyroAngleCommand class.
**/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "commands/RotateDegreesCommand.h"

/** This is the command to rotate the robot to a given gyro angle. */
class RotateToGyroAngleCommand
    : public frc2::CommandHelper<frc2::CommandBase, RotateToGyroAngleCommand> {
 public:
  RotateToGyroAngleCommand(double TargetAngle);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
  
  double TargetAngle;

  RotateDegreesCommand baseCmd {0};
};
