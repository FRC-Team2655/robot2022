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
    intakeSol1.Set(frc::DoubleSolenoid::kForward);
    intakeSol2.Set(frc::DoubleSolenoid::kForward);
}

/** @brief Controls the Solenoid to bring the intake in
 * @return void
 */
void IntakeSubsystem::IntakeIn() {
    intakeSol1.Set(frc::DoubleSolenoid::kReverse);
    intakeSol2.Set(frc::DoubleSolenoid::kReverse);
}
