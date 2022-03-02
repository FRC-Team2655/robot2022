/**
 * @file IntakeInCommand.h
 * @date 3/1/20222
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Declaring the IntakeInCommand class.
**/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

/** The IntakeInCommand extends the intake arm out */
class IntakeInCommand
    : public frc2::CommandHelper<frc2::CommandBase, IntakeInCommand> {
 public:
  IntakeInCommand();

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
};
