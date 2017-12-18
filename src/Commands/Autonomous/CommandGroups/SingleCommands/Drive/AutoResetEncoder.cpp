#include "AutoResetEncoder.h"
#include "Robot.h"
#include "RobotMap.h"

AutoResetEncoder::AutoResetEncoder()
{
	Requires(Robot::drivebase);
}

void AutoResetEncoder::Initialize(){
	//Robot::drivebase->ResetEncoderPosition();
}

void AutoResetEncoder::Execute(){
	Robot::drivebase->ResetEncoderPosition();
}

bool AutoResetEncoder::IsFinished(){
	return true;
}

void AutoResetEncoder::End(){
}

void AutoResetEncoder::Interrupted(){
	End();
}
