/**
 * @file ReleaseClimberCommand.h
 * @date 3/5/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Declaring the ReleaseClimberCommand class.
**/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

/** The ReleaseClimberCommand is the command to release the climber and move it up using the PID. */
class ReleaseClimberCommand
    : public frc2::CommandHelper<frc2::CommandBase, ReleaseClimberCommand> {
 public:
  ReleaseClimberCommand();

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
};
