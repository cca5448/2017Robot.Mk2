#include "WPILib.h"
//#include "Commands/Vision/FindGoal.h"
#include "Vision.h"

Vision::Vision() : Subsystem("Vision")
{
	CameraServer::GetInstance()->StartAutomaticCapture();
}

void Vision::InitDefaultCommand()
{
	//SetDefaultCommand(new FindGoal());
}

void Vision::FindGoal()
{
	//Find the goal
}
