#include <Commands/Setup/NextAuton.h>
#include "Robot.h"

NextAuton::NextAuton()
{
	Requires(Robot::setup); //requires the shooter subsystem
}

void NextAuton::Initialize()
{
	SmartDashboard::PutNumber("Auton Mode", Robot::setup->ReturnAutonMode());
}

void NextAuton::Execute()
{
	Robot::setup->NextAutonMode();
	SmartDashboard::PutNumber("Auton Mode", Robot::setup->ReturnAutonMode());
}

bool NextAuton::IsFinished()
{
	return true;
}

void NextAuton::End()
{
}

void NextAuton::Interrupted()
{
	End();
}
