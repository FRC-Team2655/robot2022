/**
 * @file RunBeltsCommand.h
 * @date 3/1/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Declaring the RunBeltsCommand.h class.
**/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

/** The RunBeltsCommand runs the belts using the belt logic */
class RunBeltsCommand
    : public frc2::CommandHelper<frc2::CommandBase, RunBeltsCommand> {
 public:
  RunBeltsCommand();

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
};
