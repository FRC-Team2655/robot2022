/**
 * @file Input.h
 * @date 1/15/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Creates the Input class to handle the input of the Joystick.
**/

#pragma once

#include <frc/Joystick.h>
#include <frc2/command/button/JoystickButton.h>
#include <frc2/command/SequentialCommandGroup.h>

#include "Commands/RunBeltsCommand.h"
#include "Commands/IntakeOutCommand.h"
#include "Commands/IntakeInCommand.h"

#include "team2655/joystick.hpp"

/** This is the input class. It deals with the joystick input. */
class Input {
public:
    Input();

    /** Defining the Joystick */
    frc::Joystick *joystick;

    /** Defining all the joystick buttons */
    frc2::JoystickButton *xBtn;
    frc2::JoystickButton *squareBtn;  
    frc2::JoystickButton *triangleBtn;
    frc2::JoystickButton *circleBtn;
    frc2::JoystickButton *l2Btn;
    frc2::JoystickButton *l1Btn;
    frc2::JoystickButton *r2Btn;
    frc2::JoystickButton *r1Btn;
    frc2::JoystickButton *shareBtn;
    frc2::JoystickButton *optionsBtn;
    frc2::JoystickButton *rightStickBtn;

    /** Configurations for the joystick deadband and cubic function. */
    team2655::jshelper::AxisConfig driveAxisConfig = team2655::jshelper::createAxisConfig(.1, 0, 0.5);
    team2655::jshelper::AxisConfig rotateAxisConfig = team2655::jshelper::createAxisConfig(0.1);
private:
    /** Instance of the intake out command */
    IntakeOutCommand intakeOut {};
    /** Instance of the intake in command */
    IntakeInCommand intakeIn {};
    /** Instance of the run belts command */
    RunBeltsCommand runBelts {};
};