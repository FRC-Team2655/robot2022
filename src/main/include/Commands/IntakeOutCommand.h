/**
 * @file IntakeOutCommand.h
 * @date 3/1//2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Declaring the IntakeInCommand class.
**/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

/** The IntakeOutCommand brings the intake in */
class IntakeOutCommand
    : public frc2::CommandHelper<frc2::CommandBase, IntakeOutCommand> {
 public:
  IntakeOutCommand();

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
};
