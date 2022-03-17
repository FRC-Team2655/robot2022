/**
 * @file ClimbSubsystem.cpp
 * @date 3/5/2022
 * @author Jonah Boan, Aidan Cobb, Alex Nolan
 * @brief Source code dealing with the climber.
**/

#include "Subsystems/ClimbSubsystem.h"

/** constructor for the climb subsystem */
ClimbSubsystem::ClimbSubsystem() {
    // PID Values for the right climb motor controller
    rightClimbPID.SetP(KPRIGHTCLIMBER);
    rightClimbPID.SetI(KIRIGHTCLIMBER);
    rightClimbPID.SetD(KDRIGHTCLIMBER);
    rightClimbPID.SetFF(KFFRIGHTCLIMBER);
    rightClimbPID.SetIZone(0);
    rightClimbPID.SetOutputRange(-1, 1);

    // PID values for the left climb motor controller
    leftClimbPID.SetP(KPLEFTCLIMBER);
    leftClimbPID.SetI(KILEFTCLIMBER);
    leftClimbPID.SetD(KDLEFTCLIMBER);
    leftClimbPID.SetFF(KFFLEFTCLIMBER);
    leftClimbPID.SetIZone(0);
    leftClimbPID.SetOutputRange(-1, 1);

    // Burning the settings on the left and right climber motor controllers to ensure that the settings are kept.
    leftClimber.BurnFlash();
    rightClimber.BurnFlash();
}

/** This method will be called once per scheduler run */
void ClimbSubsystem::Periodic() {
}


/** @brief Function to move both climbers down. Percentage should always be less than 0.5 
 * @param percentage the percentage to move the climer at: less than .5
 * @return void
*/
void ClimbSubsystem::MoveClimberDown(double percentage) {
    // Applying the given percentage to the climb motor controllers
    rightClimber.Set(percentage);
    leftClimber.Set(-percentage);
}


/** @brief Function to move both climbers up. Percentage should always be less than 0.5 
 * @param percentage the percentage to move the climer at: less than .5
 * @return void
*/
void ClimbSubsystem::MoveClimberUp(double percentage) {
    // Applying the given percentage to the climb motor controllers
    rightClimber.Set(-percentage);
    leftClimber.Set(percentage);
}

/** @brief Function to move the climber up using the PID
 * @return void
*/
void ClimbSubsystem::ReleaseClimber() {
    // Setting the position to both climb motor controllers and using the PID to run it.
    rightClimbPID.SetReference(-CLIMBERMAXHEIGHT, rev::CANSparkMaxLowLevel::ControlType::kPosition);
    leftClimbPID.SetReference(CLIMBERMAXHEIGHT, rev::CANSparkMaxLowLevel::ControlType::kPosition);
}

/** @brief Function to set the climber motor controllers in coast mode.
 * @return void
 */ 
void ClimbSubsystem::SetClimberCoastMode() {
    // Setting the climber motor controllers in coast mode.
    leftClimber.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
    rightClimber.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
}

/** @brief Function to set the climber motor controllers in brake mode.
 * @return void
 */ 
void ClimbSubsystem::SetClimberBrakeMode() {
    // Setting the climber motor controllers in brake mode.
    leftClimber.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
    rightClimber.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
}

/** @brief Function to stop the climber motor controllers.
 * @return void
 */ 
void ClimbSubsystem::StopClimber() {
    // Setting the left and right climbers to zero.
    leftClimber.Set(0);
    rightClimber.Set(0);
}

/** @brief Function to return the left climber position in terms of rotations.
 * @return The left climber position read by the encoder
 */ 
double ClimbSubsystem::GetLeftClimberPosition() {
    // Return the position of the left climber encoder.
    return leftClimberEncoder.GetPosition();
}

/** @brief Function to return the right climber position in terms of rotations.
 * @return The right climber position read by the encoder
 */ 
double ClimbSubsystem::GetRightClimberPosition() {
    // Return the position of the right climber encoder.
    return rightClimberEncoder.GetPosition();
}

/** @brief Function to reset both the left and the right climber motor positions read by the encoders in the down position. Down is zero for both.
 * @return void
 */ 
void ClimbSubsystem::ResetClimberDown() {
    // Set both the left and right climber encoder positions to zero.
    leftClimberEncoder.SetPosition(0);
    rightClimberEncoder.SetPosition(0);
}

/** @brief Function to reset both the left and the right climber motor positions read by the encoders in the up position. Up is +max height for left and -max height for right.
 * @return void
 */ 
void ClimbSubsystem::ResetClimberUp() {
    // Set the left climber encoder to +max height and the right climber encoder to -max height.
    leftClimberEncoder.SetPosition(CLIMBERMAXHEIGHT);
    rightClimberEncoder.SetPosition(-CLIMBERMAXHEIGHT);
}