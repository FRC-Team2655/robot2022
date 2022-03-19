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
private:
  /* Want robot to be able to accelerate to max in 250ms. 
     Update interval of 20ms -> 250ms/20ms = 12.5 */
  double accelLimit = (1.0/12.5);
};
