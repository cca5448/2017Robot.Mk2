#include "AutoDriveForward.h"
#include "Robot.h"
#include "RobotMap.h"

AutoDriveForward::AutoDriveForward(int distance)
{
	Requires(Robot::drivebase);
	SmartDashboard::PutString("ADF",std::to_string(distance));
	m_TARGET_DISTANCE = Robot::drivebase->ConvertInchesToEncoder(distance);
}

void AutoDriveForward::Initialize(){
	Robot::drivebase->ResetEncoderPosition();
}

void AutoDriveForward::Execute(){
	Robot::drivebase->DriveTank(AUTON_DRIVE_SPEED,AUTON_DRIVE_SPEED);
}

bool AutoDriveForward::IsFinished(){
	return (Robot::drivebase->ReturnEncoderDistance(0,0,0) >= m_TARGET_DISTANCE);
}

void AutoDriveForward::End(){
	Robot::drivebase->DriveTank(0,0);
}

void AutoDriveForward::Interrupted(){
	End();
}
