#include <Commands/Climber/StartClimberUp.h>
#include "Robot.h"

StartClimberFwd::StartClimberFwd()
{
	Requires(Robot::climber);
}

void StartClimberFwd::Initialize()
{
//	SmartDashboard::PutString("Feeder Running","initfwd");
}

void StartClimberFwd::Execute()
{
	Robot::climber->StartClimberFwd();
	//printf("StartClimberFwd");
	SmartDashboard::PutString("Climber Running","fwd");
}

bool StartClimberFwd::IsFinished()
{
	return true;
}

void StartClimberFwd::End()
{
}

void StartClimberFwd::Interrupted()
{
	End();
}
