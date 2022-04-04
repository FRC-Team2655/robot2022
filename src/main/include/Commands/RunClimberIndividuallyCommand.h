/**
 * @file RunClimberIndividuallyCommand.h
 * @date 4/4/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Declaring the RunClimberIndividuallyCommand.h class.
**/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

/** The RunClimberIndividuallyCommand is a command to run the climber arms individually.
 * isLeftSide - Whether we are running the left side individually (false is to run the right side individually)
 * upwardSpeed - The speed to move the individual climber arm at
 */ 
class RunClimberIndividuallyCommand
    : public frc2::CommandHelper<frc2::CommandBase, RunClimberIndividuallyCommand> {
 public:
  RunClimberIndividuallyCommand(bool isLeftSide, double upwardSpeed);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

  bool isLeftSide;
  double upwardSpeed;
};
