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
#include <frc2/command/ParallelCommandGroup.h>
#include "frc2/command/InstantCommand.h"

#include "team2655/joystick.hpp"

#include "RobotMap.h"

#include "Commands/RunBeltsCommand.h"
#include "Commands/IntakeOutCommand.h"
#include "Commands/IntakeInCommand.h"
#include "Commands/RunShooterDripoutSpeedCommand.h"
#include "Commands/RunShooterVelocityCommand.h"
#include "Commands/RunAllBeltsCommand.h"
#include "Commands/RunIntakeRollersCommand.h"
#include "Commands/MoveClimberDownCommand.h"
#include "Commands/MoveClimberUpCommand.h"
#include "Commands/ReleaseClimberCommand.h"
#include "Commands/ResetClimberDownCommand.h"
#include "Commands/ResetClimberUpCommand.h"
#include "Commands/DriveJoystickCommand.h"
#include "frc2/command/button/POVButton.h"


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
    frc2::JoystickButton *leftStickBtn;
    frc2::JoystickButton *psBtn;
        frc2::POVButton *dPadDown;


    /** Configurations for the joystick deadband and cubic function. */
    team2655::jshelper::AxisConfig driveAxisConfig = team2655::jshelper::createAxisConfig(.1, 0, 0.5);
    team2655::jshelper::AxisConfig rotateAxisConfig = team2655::jshelper::createAxisConfig(0.1);
private:
    /** Instance of the intake out command */
    IntakeOutCommand intakeOut {};
    /** Instance of the intake in command */
    IntakeInCommand intakeIn {};
    /** Instance of the run belts with belt logic command */
    RunBeltsCommand runBelts {};
    /** Instance of the run shooter dripout speed command */
    RunShooterDripoutSpeedCommand runShooterDripoutSpeed {};
    /** Instance of the run shooter velocity command */
    RunShooterVelocityCommand runShooterVelocity {};
    /** Instance of the run all belts without belt logic command. */
    RunAllBeltsCommand runAllBelts {};
    /** Instance of the run intake rollers command. */
    RunIntakeRollersCommand runIntakeRollers {};
    /** Instance of the move climber up command */
    MoveClimberUpCommand moveClimberUp {CLIMBINGSPEED};
    /** Instance of the move climber down command */
    MoveClimberDownCommand moveClimberDown {CLIMBINGSPEED};
    /** Instance of the release climber command (moving climber up using PID) */
    ReleaseClimberCommand releaseClimber {};
    /** Instance of the reset climber up command class */
    ResetClimberUpCommand resetClimberUp {};
    /** Instance of the reset climber down command class */
    ResetClimberDownCommand resetClimberDown {};
};