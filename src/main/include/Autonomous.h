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

/** Class for all the Autonomous routines */
class Autonomous {
public:
    Autonomous();

    frc2::Command* ShootPreload();
    frc2::Command* DriveBackwards();
    void ShootPreloadAndDrive();
    void TwoBallAuto();
};