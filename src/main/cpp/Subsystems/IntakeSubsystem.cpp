/**
 * @file IntakeSubsystem.h
 * @date 1/15/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Contains the code dealing with intake control.
**/

#include "Subsystems/IntakeSubsystem.h"

/** The intake subsystem constructor */
IntakeSubsystem::IntakeSubsystem() {
    // Inverting the intake rollers so that they move in the correct direction
    intakeRollers.SetInverted(true);

    // Burning the settings to the intake rollers motor controller to ensure that the settings are maintained.
    intakeRollers.BurnFlash();
}

/** @brief Run the intake rollers at a set speed 
 * @param percentage The percentage to run the intake rollers at.
 * @return void
*/
void IntakeSubsystem::RunIntakeRollers(double percentage) {
    intakeRollers.Set(percentage);
}

/** @brief This method will be called once per scheduler run
 *  @return void
 */
void IntakeSubsystem::Periodic() {}

/** @brief Controls the Solenoid to bring the intake out 
 * @return void
*/
void IntakeSubsystem::IntakeOut() {
    intakeLeftSol.Set(LEFTSOLOUT);
    intakeRightSol.Set(RIGHTSOLOUT);

    // Set the variable to track whether the intake is in to false
    isIntakeIn = false;
}

/** @brief Controls the Solenoid to bring the intake in
 * @return void
 */
void IntakeSubsystem::IntakeIn() {
    intakeLeftSol.Set(LEFTSOLIN);
    intakeRightSol.Set(RIGHTSOLIN);

    // Set the variable to track whether the intake is in to true
    isIntakeIn = true;
}

/** @brief Function to set the intake rollers into coast mode.
 * @return void
 */ 
void IntakeSubsystem::SetIntakeRollersCoastMode() {
    // Setting the intake rollers into coast mode.
    intakeRollers.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
}

/** @brief Function to set the intake rollers into brake mode.
 * @return void
 */ 
void IntakeSubsystem::SetIntakeRollersBrakeMode() {
    // Setting the intake rollers into brake mode.
    intakeRollers.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
}