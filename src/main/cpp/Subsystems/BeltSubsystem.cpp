/**
 * @file BeltSubsystem.cpp
 * @date 1/18/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Source code for the belt subsystem.
**/

#include "Subsystems/BeltSubsystem.h"

/** Constructor for the belt subsystem */
BeltSubsystem::BeltSubsystem() {
    /** Add the red and blue colors as available colors to match */
    colorMatcher.AddColorMatch(blueTarget);
    colorMatcher.AddColorMatch(redTarget);
}

/** This method will be called once per scheduler run */
void BeltSubsystem::Periodic() {}

/** Function for running upper belts */
void BeltSubsystem::RunUpperBelts() {
    /** Set the upper belts to the belt speed */
    upperBelt1.Set(BELTSPEED);
    upperBelt2.Set(BELTSPEED);
}

/** Function for running lower belts */
void BeltSubsystem::RunLowerBelts() {
    /** Set the lower belts to the belt speed */
    lowerBelt1.Set(BELTSPEED);
    lowerBelt2.Set(BELTSPEED);
}

/** Function for running all belts */
void BeltSubsystem::RunAllBelts() {
    /** Run the override functions for the upper and lower belts */
    RunUpperBelts();
    RunLowerBelts();
}

/** Function to stop the upper belts from running */
void BeltSubsystem::StopUpperBelts() {
    upperBelt1.Set(0);
    upperBelt2.Set(0);
}

/** Function to stop the lower belts from running */
void BeltSubsystem::StopLowerBelts() {
    lowerBelt1.Set(0);
    lowerBelt2.Set(0);
}

/** Function to stop all the belts from running */
void BeltSubsystem::StopAllBelts() {
    StopUpperBelts();
    StopLowerBelts();
}

/** Check whether the proximity sensor on the color sensor detects a ball */
bool BeltSubsystem::GetColorSensorProximity() {
    /** If the color sensor proximity distance is less than the proximity distance threshold, then the proximity sensor is not considered "triggered" */
    if (colorSensor.GetProximity() < COLORSENSORPROXIMITYDISTANCE) {
        isColorSensorProximityTriggered = false;
    /** If the color sensor proximity distance is greater than the proximity distance threshold, then the proximity sensor is considered "triggered" */
    }else{
        isColorSensorProximityTriggered = true;
    }

    /** Return whether the color sensor proximity sensor is "triggered" */
    return isColorSensorProximityTriggered;
}

/** Function to get the currently detected color */
std::string BeltSubsystem::GetDetectedColor() {
    /** Get the currently detected color */
    frc::Color detectedColor = colorSensor.GetColor();
    /** Match the currently detected color to one of the registered colors (red and blue) */
    frc::Color matchedColor = colorMatcher.MatchClosestColor(detectedColor, confidence);

    /** If the matched color is blue, set the color string to blue */
    if (matchedColor == blueTarget) {
      colorString = "Blue";
    /** If the matched color is red, set the color string to red */
    } else if (matchedColor == redTarget) {
      colorString = "Red";
    /** If the matched color is not one of the detected colors (red or blue), set the color string to unknown */
    }else{
      colorString = "Unknown";
    }

    /** Return the color string */
    return colorString;
}

/** Function to run belts using belt logic */
void BeltSubsystem::RunBelts() {
    /** If the upper and lower proximity sensors are not triggered, run all belts */
    if ((GetColorSensorProximity() == false) && (proximSensor.Get() == false)) {
        RunAllBelts();
    /** If the upper proximity sensor is not triggered and the lower one is, run all belts */
    }else if ((GetColorSensorProximity() == false) && (proximSensor.Get() == true)) {
        RunAllBelts();
    /** If the upper proximity sensor is triggered and the lower one is not, only run the lower belts */
    }else if ((GetColorSensorProximity() == true) && (proximSensor.Get() == false)) {
        RunLowerBelts();
        StopUpperBelts();
    /** If both the upper and lower proximity sensors are triggered, stop running all the belts */
    }else if ((GetColorSensorProximity() == true) && (proximSensor.Get() == true)) {
        StopAllBelts();
    }
}