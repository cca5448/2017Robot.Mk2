#include <Commands/Climber/StartClimberDown.h>
#include "Robot.h"

StartClimberRev::StartClimberRev()
{
	Requires(Robot::climber);
}

void StartClimberRev::Initialize()
{
//	SmartDashboard::PutString("Feeder Running","initrev");
}

void StartClimberRev::Execute()
{
	Robot::climber->StartClimberRev();
	SmartDashboard::PutString("Climber Running","rev");
}

bool StartClimberRev::IsFinished()
{
	return true;
}

void StartClimberRev::End()
{
}

void StartClimberRev::Interrupted()
{
	End();
}
