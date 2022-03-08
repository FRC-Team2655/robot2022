/**
 * @file ResetClimberUpCommand.h
 * @date 3/7/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Declaring the ResetClimberUpCommand class.
**/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

/** This command resets the climber encoders in the up position. */
class ResetClimberUpCommand
    : public frc2::CommandHelper<frc2::CommandBase, ResetClimberUpCommand> {
 public:
  ResetClimberUpCommand();

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
};
