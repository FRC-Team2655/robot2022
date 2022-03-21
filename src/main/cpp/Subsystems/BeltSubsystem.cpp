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
    //colorMatcher.AddColorMatch(blueTarget);
    //colorMatcher.AddColorMatch(redTarget);
}

/** @brief This method will be called once per scheduler run 
 * @return void
*/
void BeltSubsystem::Periodic() {}

/** @brief Function for running belts 
 * @return void
*/
void BeltSubsystem::RunAllBelts() {
    /** Set the lower belts to the belt speed */
    leftBelt.Set(0.25);
    rightBelt.Set(0.20);
}

/** @brief Function to stop the belts from running 
 * @return void
*/
void BeltSubsystem::StopBelts() {
    leftBelt.Set(0);
    rightBelt.Set(0);
}

/** @brief Check whether the proximity sensor on the color sensor detects a ball 
 * @return A bool determining whether the proximity sensor is triggered.
*/
//bool BeltSubsystem::GetColorSensorProximity() {
    /** If the color sensor proximity distance is less than the proximity distance threshold, then the proximity sensor is not considered "triggered" */
    //if (colorSensor.GetProximity() < COLORSENSORPROXIMITYDISTANCE) {
      //  isColorSensorProximityTriggered = false;
    /** If the color sensor proximity distance is greater than the proximity distance threshold, then the proximity sensor is considered "triggered" */
    //}else{
      //  isColorSensorProximityTriggered = true;
    //}

    /** Return whether the color sensor proximity sensor is "triggered" */
    //return isColorSensorProximityTriggered;
//}

/** @brief Function to get the currently detected color 
 * @return A string containing the detected color: blue, red, or unknown.
*/
//std::string BeltSubsystem::GetDetectedColor() {
    /** Get the currently detected color */
  //  frc::Color detectedColor = colorSensor.GetColor();
    /** Match the currently detected color to one of the registered colors (red and blue) */
    //frc::Color matchedColor = colorMatcher.MatchClosestColor(detectedColor, confidence);

    /** If the matched color is blue, set the color string to blue */
    //if (matchedColor == blueTarget) {
      //colorString = "Blue";
    /** If the matched color is red, set the color string to red */
    //} else if (matchedColor == redTarget) {
      //colorString = "Red";
    /** If the matched color is not one of the detected colors (red or blue), set the color string to unknown */
    //}else{
      //colorString = "Unknown";
    //}

    /** Return the color string */
    //return colorString;
//}

/** @brief Function to put the belts in brake mode.
 * @return void
 */ 
void BeltSubsystem::SetBeltsBrakeMode() {
    // Setting all the belt motor controllers in brake mode.
    leftBelt.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
    rightBelt.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);

}

/** @brief Function to put the belts in coast mode.
 * @return void
 */ 
void BeltSubsystem::SetBeltsCoastMode() {
    // Setting all the belt motor controllers in coast mode.
    leftBelt.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
    rightBelt.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
}

/** @brief Function to run belts using belt logic 
 * @return void
*/
void BeltSubsystem::RunBelts() {
    /** If the upper and lower proximity sensors are not triggered, run all belts */
    //if ((GetColorSensorProximity() == false) && (proximSensor.Get() == false)) {
      //  RunAllBelts();
    /** If the upper proximity sensor is not triggered and the lower one is, run all belts */
    //}else if ((GetColorSensorProximity() == false) && (proximSensor.Get() == true)) {
      //  RunAllBelts();
    /** If the upper proximity sensor is triggered and the lower one is not, only run the lower belts */
    /*}else if ((GetColorSensorProximity() == true) && (proximSensor.Get() == false)) {
        RunLowerBelts();
        StopUpperBelts();*/
    /** If both the upper and lower proximity sensors are triggered, stop running all the belts */
    /*}else if ((GetColorSensorProximity() == true) && (proximSensor.Get() == true)) {
        StopAllBelts();
    }*/

    // If the proximity sensor does not see anything, run the belts. Else, if it sees something, stop the belts from runnng.
    if (proximSensor.Get() == true) {
        RunAllBelts();
    }else{
        StopBelts();
    }
}