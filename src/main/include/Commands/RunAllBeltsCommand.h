/**
 * @file RunAllBeltsCommand.h
 * @date 3/2/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Declaring the RunAllBeltsCommand.h class.
**/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

/** The RunAllBeltsCommand class runs all the belts at a fixed percentage without belt logic */
class RunAllBeltsCommand
    : public frc2::CommandHelper<frc2::CommandBase, RunAllBeltsCommand> {
 public:
  RunAllBeltsCommand();

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
};
