#include "Commands/DriveBase/TeleopTankDrive.h"
#include "Robot.h"

TeleopTankDrive::TeleopTankDrive()
{
	Requires(Robot::drivebase); //requires the drivebase subsystem
}

void TeleopTankDrive::Initialize()
{
	//Robot::drivebase->ResetGyro();
}

void TeleopTankDrive::Execute()
{
	//Call DriveTank(double throttle, double steer);
	Robot::drivebase->DriveTank(Robot::oi->GetThrottleAxis(), Robot::oi->GetSteerAxis());  //drive the wheels with the values returned from OI
	//Robot::drivebase->ReturnEncoderDistance(0,0,0);
	//Robot::drivebase->ReturnGyroAngle();
}

bool TeleopTankDrive::IsFinished()
{
	return false;
}

void TeleopTankDrive::End()
{
	Robot::drivebase->DriveTank(0,0); //sets the speed to 0 so doesnt drive or continue driving
}

void TeleopTankDrive::Interrupted()
{
	End();
}

