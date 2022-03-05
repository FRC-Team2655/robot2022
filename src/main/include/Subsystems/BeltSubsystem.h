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

  void RunAllBelts();
  void RunLowerBelts();
  void RunUpperBelts();

  void StopAllBelts();
  void StopLowerBelts();
  void StopUpperBelts();

  void RunBelts();

  bool GetColorSensorProximity();

  void SetBeltsBrakeMode();
  void SetBeltsCoastMode();

  std::string GetDetectedColor();

 private:
 /** Lower belt on the left side motor controller definition */
  rev::CANSparkMax lowerBelt1 {LOWERBELT1ID, rev::CANSparkMax::MotorType::kBrushless};
  /** Lower belt on the right side motor controller definition */
  rev::CANSparkMax lowerBelt2 {LOWERBELT2ID, rev::CANSparkMax::MotorType::kBrushless};
  /** Upper belt on the left side motor controller definition */
  rev::CANSparkMax upperBelt1 {UPPERBELT1ID, rev::CANSparkMax::MotorType::kBrushless};
  /** Upper belt on the right side motor controller definition */
  rev::CANSparkMax upperBelt2 {UPPERBELT2ID, rev::CANSparkMax::MotorType::kBrushless};

  /** Proximity Sensor Definition */
  frc::DigitalInput proximSensor {PROXIMITYSENSORPORT};

  /** I2C Port Definition */
  static constexpr auto i2cPort = frc::I2C::Port::kOnboard;
  /** Color Sensor Definition */
  rev::ColorSensorV3 colorSensor{i2cPort};
  /** Used to determine which color is being matched */
  rev::ColorMatch colorMatcher;
  /** Definition of the blue target color */
  static constexpr frc::Color blueTarget = frc::Color(0.143, 0.427, 0.429);
  /** Definition of the red target color */
  static constexpr frc::Color redTarget = frc::Color(0.561, 0.232, 0.114);
  /** Definition of the color string. Will hold the detected color */
  std::string colorString = "Unknown";
  /** The confidence for the color sensor */
  double confidence = 0.0;

  /** Whether the proximity sensor on the color sensor is "triggered" */
  bool isColorSensorProximityTriggered = false;
};
