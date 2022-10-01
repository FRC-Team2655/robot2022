/**
 * @file Autonomous.h
 * @date 2/23/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Declaring the Autonomous routines.
**/

#pragma once

#include "frc2/command/Command.h"

#include <frc2/command/ParallelRaceGroup.h>
#include <frc2/command/SequentialCommandGroup.h>
#include "Commands/RunShooterAutoCommand.h"
#include "Commands/DriveDistanceCommand.h"
#include "Commands/RunAllBeltsCommand.h"
#include "Commands/RunShooterVelocityCommand.h"
#include "Commands/DelayMillisecondsCommand.h"
#include <frc2/command/ParallelCommandGroup.h>

#include "Commands/IntakeOutCommand.h"
#include "Commands/IntakeInCommand.h"
#include "Commands/RunIntakeRollersCommand.h"
#include "Commands/RotateDegreesCommand.h"
#include "Commands/RunBeltsCommand.h"

#include "Commands/ShootOneBallCommand.h"

/** Class for all the Autonomous routines */
class Autonomous {
public:
    Autonomous();

    frc2::Command* RotateDegreesTest();
    frc2::Command* ShootPreloadAndDrive();
    frc2::Command* DriveForwardOffTarmac();
    frc2::Command* TwoBallAuto();
    frc2::Command* ThreeBallAuto();
};