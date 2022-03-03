/**
 * @file RunShooterVelocityCommand.h
 * @date 3/2/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Declaring the RunShooterVelocityCommand class.
**/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

/** The RunShooterVelocityCommand class runs the PID to ramp the shooter up to a fixed velocity. */
class RunShooterVelocityCommand
    : public frc2::CommandHelper<frc2::CommandBase, RunShooterVelocityCommand> {
 public:
  RunShooterVelocityCommand();

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
};
