/**
 * @file IntakeSubsystem.h
 * @date 1/15/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Contains the code dealing with intake control.
**/

#include "Subsystems/IntakeSubsystem.h"

/** The intake subsystem constructor */
IntakeSubsystem::IntakeSubsystem() {
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
    intakeLeftSol.Set(frc::DoubleSolenoid::kForward);
    intakeRightSol.Set(frc::DoubleSolenoid::kForward);
}

/** @brief Controls the Solenoid to bring the intake in
 * @return void
 */
void IntakeSubsystem::IntakeIn() {
    intakeLeftSol.Set(frc::DoubleSolenoid::kReverse);
    intakeRightSol.Set(frc::DoubleSolenoid::kReverse);
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