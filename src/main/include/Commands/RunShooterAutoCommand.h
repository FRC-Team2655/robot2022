/**
 * @file RunShooterAutoCommand.h
 * @date 3/21/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Declaring the RunShooterAutoCommand.h class.
**/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

/** The RunShooterAutoCommand runs the shooter, but does not stop it once the command ends */
class RunShooterAutoCommand
    : public frc2::CommandHelper<frc2::CommandBase, RunShooterAutoCommand> {
 public:
  RunShooterAutoCommand();

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
};
