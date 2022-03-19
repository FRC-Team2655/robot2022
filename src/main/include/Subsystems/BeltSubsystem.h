/**
 * @file BeltSubsystem.h
 * @date 1/18/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Defines the BeltSubsystem class.
**/

#pragma once

#include <iostream>

#include <RobotMap.h>
#include <frc2/command/SubsystemBase.h>

#include <rev/CANSparkMax.h>
#include <rev/ColorSensorV3.h>
#include <rev/ColorMatch.h>

#include <frc/I2C.h>
#include <frc/DigitalInput.h>

/** The belt subsystem controlls the belt */
class BeltSubsystem : public frc2::SubsystemBase {
 public:
  BeltSubsystem();

  void Periodic() override;

  void RunBelts();

  void StopBelts();

  void RunAllBelts();
  void RunBeltsReverse();

  //bool GetColorSensorProximity();

  void SetBeltsBrakeMode();
  void SetBeltsCoastMode();

  //std::string GetDetectedColor();

  /** Proximity Sensor Definition */
  frc::DigitalInput proximSensor {PROXIMITYSENSORPORT};

 private:
 /** Belt on the left side motor controller definition */
  rev::CANSparkMax leftBelt {LEFTBELTID, rev::CANSparkMax::MotorType::kBrushless};
  /** Belt on the right side motor controller definition */
  rev::CANSparkMax rightBelt {RIGHTBELTID, rev::CANSparkMax::MotorType::kBrushless};

  /** I2C Port Definition */
  //static constexpr auto i2cPort = frc::I2C::Port::kOnboard;
  /** Color Sensor Definition */
  //rev::ColorSensorV3 colorSensor{i2cPort};
  /** Used to determine which color is being matched */
  //rev::ColorMatch colorMatcher;
  /** Definition of the blue target color */
  //static constexpr frc::Color blueTarget = frc::Color(0.143, 0.427, 0.429);
  /** Definition of the red target color */
  //static constexpr frc::Color redTarget = frc::Color(0.561, 0.232, 0.114);
  /** Definition of the color string. Will hold the detected color */
  //std::string colorString = "Unknown";
  /** The confidence for the color sensor */
  //double confidence = 0.0;

  /** Whether the proximity sensor on the color sensor is "triggered" */
  //bool isColorSensorProximityTriggered = false;
};
