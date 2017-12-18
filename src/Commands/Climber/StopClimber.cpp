#include "Commands/Climber/StopClimber.h"
#include "Robot.h"

StopClimber::StopClimber()
{
	Requires(Robot::climber); //requires the shooter subsystem
}

void StopClimber::Initialize()
{
	SmartDashboard::PutString("Climber Running","initfalse");
}

void StopClimber::Execute()
{
	Robot::climber->StopClimber();
	SmartDashboard::PutString("Climber Running","false");
}

bool StopClimber::IsFinished()
{
	return true;
}

void StopClimber::End()
{
}

void StopClimber::Interrupted()
{
	End();
}
