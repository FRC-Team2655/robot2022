/**
 * @file RunIntakeRollersCommand.h
 * @date 3/2/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Declaring the RunIntakeRollersCommand.h class.
**/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

/** The RunIntakeRollersCommand class runs the intake rollers at a fixed percentage. */
class RunIntakeRollersCommand
    : public frc2::CommandHelper<frc2::CommandBase, RunIntakeRollersCommand> {
 public:
  RunIntakeRollersCommand();

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
};
