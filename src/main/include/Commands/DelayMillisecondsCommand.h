/**
 * @file DelayMillisecondsCommand.h
 * @date 3/17/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Declaring the DelayMillisecondsCommand class.
**/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc/Timer.h>

/** This is the command to delay a given amount of milliseconds when run. */
class DelayMillisecondsCommand
    : public frc2::CommandHelper<frc2::CommandBase, DelayMillisecondsCommand> {
 public:
  DelayMillisecondsCommand(double time_ms);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

private:
  double time_ms;
  double stopTime;
  double currentTime;
};
