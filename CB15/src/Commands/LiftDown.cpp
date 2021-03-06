// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "LiftDown.h"
#include "../Constants.h"

LiftDown::LiftDown() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	initPot = 0; //Stores the pot value at the start of the command
}

// Called just before this Command runs the first time
void LiftDown::Initialize() {
	initPot = RobotMap::toteElevatortotePot->GetValue(); //Store the starting pot value
}

// Called repeatedly when this Command is scheduled to run
void LiftDown::Execute() {
	RobotMap::toteElevatortoteDrive->Set(-0.25); //Drive the motor backwards
}

// Make this return true when this Command no longer needs to run execute()
bool LiftDown::IsFinished() {
	if(initPot-RobotMap::toteElevatortotePot->GetValue()<POT_LIFT_DIFFERENCE) { //When the lift travels the length of a tote, stop
		return false;
	}
	else {
		return true; //Otherwise, keep going
	}
}

// Called once after isFinished returns true
void LiftDown::End() {
	RobotMap::toteElevatortoteDrive->Set(0); //Stop the motor when the command finishes
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LiftDown::Interrupted() {
	RobotMap::toteElevatortoteDrive->Set(0);
}
