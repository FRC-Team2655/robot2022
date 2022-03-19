/**
 * @file ReverseBeltsCommand.h
 * @date 3/18/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Declaring the ReverseBeltsCommand class.
**/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

/** The ReverseBeltsCommand is the command to run the belts in the reverse direction */
class ReverseBeltsCommand
    : public frc2::CommandHelper<frc2::CommandBase, ReverseBeltsCommand> {
 public:
  ReverseBeltsCommand();

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
};
