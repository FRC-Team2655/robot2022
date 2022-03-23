/**
 * @file DriveJoystickCommand.h
 * @date 1/15/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Declaring the DriveJoystickCommand class.
**/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "team2655/joystick.hpp"

/** The DriveJoystickCommand class drives the robot by joystick control */
class DriveJoystickCommand
    : public frc2::CommandHelper<frc2::CommandBase, DriveJoystickCommand> {
 public:
  DriveJoystickCommand();

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;


};
