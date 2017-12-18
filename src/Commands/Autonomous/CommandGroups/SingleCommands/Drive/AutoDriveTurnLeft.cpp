#include "AutoDriveTurnLeft.h"
#include "Robot.h"
#include "RobotMap.h"

AutoDriveTurnLeft::AutoDriveTurnLeft(float angle)
{
	m_TARGET_ANGLE = angle;
	Requires(Robot::drivebase);
}

void AutoDriveTurnLeft::Initialize()
{
	Robot::drivebase->ResetGyro();
}

void AutoDriveTurnLeft::Execute()
{
	Robot::drivebase->DriveTank(-AUTON_DRIVE_SPEED,AUTON_DRIVE_SPEED);
}

bool AutoDriveTurnLeft::IsFinished()
{
	return (Robot::drivebase->ReturnGyroAngle() <= -m_TARGET_ANGLE);
}

void AutoDriveTurnLeft::End()
{
	Robot::drivebase->DriveTank(0,0);
}

void AutoDriveTurnLeft::Interrupted()
{
	End();
}
