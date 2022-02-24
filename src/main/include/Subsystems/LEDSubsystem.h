/**
 * @file LEDSubsystem.h
 * @date 2/22/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Defines the LEDSubsystem class.
**/

#pragma once

#include <frc2/command/SubsystemBase.h>

#include "RobotMap.h"

#include <frc/motorcontrol/PWMSparkMax.h>

/** Class to control the LEDs */
class LEDSubsystem : public frc2::SubsystemBase {
 public:
  LEDSubsystem();

  void Periodic() override;

  /** Enum that contains all the possible LED colors. */
  typedef enum LEDColors{
    HotPink = 0,
    DarkRed,
    Red,
    RedOrange,
    Orange,
    Gold,
    Yellow,
    LawnGreen,
    Lime,
    DarkGreen,
    Green,
    BlueGreen,
    Aqua,
    SkyBlue,
    DarkBlue,
    Blue,
    BlueViolet,
    Violet,
    White,
    Gray,
    DarkGray,
    Black,
    LED_COLOR_COUNT,
    LED_DUAL_COLOR_MODE
  }LEDColors;

  void SetLEDColor(LEDColors color);
  LEDColors GetLEDColor();
  void setDualColorMode();

 private:
  frc::PWMSparkMax LEDController {LEDPWMPORT};
  LEDColors currentColor;
};
