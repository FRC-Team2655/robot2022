/**
 * @file Robot.h
 * @date 1/15/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Creates the Input class to handle the input of the Joystick.
**/

#pragma once

#include <frc/Joystick.h>

/** This is the input class. It deals with the joystick input. */
class Input {
public:
  Input();

    /** Defining the Joystick */
    frc::Joystick joystick {0};
private:
};