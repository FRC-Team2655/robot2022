/**
 * @file RunShooterDripoutSpeedCommand.h
 * @date 3/2/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Declaring the RunShooterDripoutSpeed class.
**/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

/** The RunShooterDripoutSpeedCommand class runs the shooter at a slow enough speed for the ball to "drip" out. */
class RunShooterDripoutSpeedCommand
    : public frc2::CommandHelper<frc2::CommandBase, RunShooterDripoutSpeedCommand> {
 public:
  RunShooterDripoutSpeedCommand();

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
};
