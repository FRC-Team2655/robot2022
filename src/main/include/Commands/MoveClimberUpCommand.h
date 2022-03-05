/**
 * @file MoveClimberUpCommand.h
 * @date 3/5/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Declaring the MoveClimberUpCommand class.
**/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

/** The MoveClimberUpCommand is the command to move the climber up at a fixed percentage. */
class MoveClimberUpCommand
    : public frc2::CommandHelper<frc2::CommandBase, MoveClimberUpCommand> {
 public:
  MoveClimberUpCommand(double percentage);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
private:
  // The percentage to run the climber at.
  double percentage;
};
