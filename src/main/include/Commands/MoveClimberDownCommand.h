/**
 * @file MoveClimberDownCommand.h
 * @date 3/5/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Declaring the MoveClimberDownCommand class.
**/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

/** The MoveClimberDownCommand is the command to move the climber down at a fixed percentage. */
class MoveClimberDownCommand
    : public frc2::CommandHelper<frc2::CommandBase, MoveClimberDownCommand> {
 public:
  MoveClimberDownCommand(double percentage);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
private:
  // The percentage to run the climber at.
  double percentage;
};
