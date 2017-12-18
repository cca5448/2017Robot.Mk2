#include <Commands/Setup/PrevAuton.h>
#include "Robot.h"

PrevAuton::PrevAuton()
{
	Requires(Robot::setup);
}

void PrevAuton::Initialize()
{
	SmartDashboard::PutNumber("Auton Mode", Robot::setup->ReturnAutonMode());
}

void PrevAuton::Execute()
{
	Robot::setup->PrevAutonMode();
	SmartDashboard::PutNumber("Auton Mode", Robot::setup->ReturnAutonMode());
}

bool PrevAuton::IsFinished()
{
	return true;
}

void PrevAuton::End()
{
}

void PrevAuton::Interrupted()
{
	End();
}
