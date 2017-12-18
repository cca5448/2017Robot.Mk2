#include "AutoDriveTurnRight.h"
#include "Robot.h"
#include "RobotMap.h"

AutoDriveTurnRight::AutoDriveTurnRight(float angle)
{
	m_TARGET_ANGLE = angle;
	Requires(Robot::drivebase);
}

void AutoDriveTurnRight::Initialize()
{
	Robot::drivebase->ResetGyro();
}

void AutoDriveTurnRight::Execute()
{
	Robot::drivebase->DriveTank(AUTON_DRIVE_SPEED,-AUTON_DRIVE_SPEED);
}

bool AutoDriveTurnRight::IsFinished()
{
	return (Robot::drivebase->ReturnGyroAngle() >= m_TARGET_ANGLE);
}

void AutoDriveTurnRight::End()
{
	Robot::drivebase->DriveTank(0,0);
}

void AutoDriveTurnRight::Interrupted()
{
	End();
}
