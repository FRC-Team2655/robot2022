/**
 * @file LEDSubsystem.cpp
 * @date 2/22/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Source code that manipulates the LEDs.
**/

#include "Subsystems/LEDSubsystem.h"

/** The Constructor for the LEDSubsystem class */
LEDSubsystem::LEDSubsystem() {};

/** @brief This method will be called once per scheduler run 
 * @return void
*/
void LEDSubsystem::Periodic() {}

/** @brief Function to set LEDS to a solid color 
 * @param color The color to set the LEDs to.
 * @return void
*/
void LEDSubsystem::SetLEDColor(LEDSubsystem::LEDColors color)
{
    /* Validate input */
    if(color >= LEDSubsystem::LEDColors::LED_COLOR_COUNT)
    {
        color = (LEDSubsystem::LEDColors) 0;
    }
    double LEDPower = 0.57;
    /* Doing some scuffed math here*/
    LEDPower += (0.02) * (double) color;
    /* Apply value to controller */
    LEDController.Set(LEDPower);
    /* Save seting */
    currentColor = color;
}

/** @brief Function to set dual pattern idle mode (purple + gold) 
 * @return void
*/
void LEDSubsystem::setDualColorMode()
{
    /* Dual colors, wave mode */
    LEDController.Set(0.53);
}

/** @brief Function to get the current LED color setting 
 * @return The current LED color of type LEDSubsystem::LEDColors.
*/
LEDSubsystem::LEDColors LEDSubsystem::GetLEDColor()
{
    return currentColor;
}