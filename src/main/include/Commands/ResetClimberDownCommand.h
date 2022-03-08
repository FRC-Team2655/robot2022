/**
 * @file ResetClimberDownCommand.h
 * @date 3/7/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Declaring the ResetClimberDownCommand class.
**/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

/** The ResetClimberDownCommand class is the command to reset the climber encoders in the down position. */
class ResetClimberDownCommand
    : public frc2::CommandHelper<frc2::CommandBase, ResetClimberDownCommand> {
 public:
  ResetClimberDownCommand();

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
};
