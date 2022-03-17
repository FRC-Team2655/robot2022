/**
 * @file DelayMillisecondsCommand.cpp
 * @date 3/17/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Source code dealing with delaying a given amount of milliseconds when run.
**/

#include "commands/DelayMillisecondsCommand.h"

#include <iostream>

/** The constructor of the DelayMillisecondsCommand class */
DelayMillisecondsCommand::DelayMillisecondsCommand(double time_ms) : time_ms(time_ms) {
}

/** @brief Called when the command is initially scheduled.
 * @return void
 */ 
void DelayMillisecondsCommand::Initialize() {
  /* Get FPGA timestamp */
  currentTime = frc::Timer::GetFPGATimestamp().value();
  stopTime = currentTime + (time_ms / 1000.0);
}

/** @brief Called repeatedly when this Command is scheduled to run
 * @return void
 */ 
void DelayMillisecondsCommand::Execute() {
  /* Update the current time */
  currentTime = frc::Timer::GetFPGATimestamp().value();
}

/** @brief Called once the command ends or is interrupted.
 * @return void
 */ 
void DelayMillisecondsCommand::End(bool interrupted) {
  if (currentTime >= stopTime)
    std::cout << "Exited DelayMillisecondsCommand due to timeout" << std::endl;
}

/** @brief Returns true when the command should end.
 * @return Whether the command should finish
 */ 
bool DelayMillisecondsCommand::IsFinished() {
  return currentTime >= stopTime;
}
