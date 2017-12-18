#include <WPILib.h>
#include "Setup.h"
#include "../RobotMap.h"


Setup::Setup() : Subsystem("Setup")
{
	m_AUTON_MODE = 0;
}

void Setup::InitDefaultCommand()
{
	SmartDashboard::PutNumber("Auton Mode",m_AUTON_MODE);
}

int Setup::ReturnAutonMode()
{
	return m_AUTON_MODE;
}

void Setup::PrevAutonMode()
{
	if (m_AUTON_MODE >= AUTON_MODE_MAX) {
		m_AUTON_MODE = AUTON_MODE_MAX;
	} else {
		m_AUTON_MODE--;
	}
	SmartDashboard::PutNumber("Auton Mode",m_AUTON_MODE);
}

void Setup::NextAutonMode()
{
	if (m_AUTON_MODE <= 0) {
		m_AUTON_MODE = 0;
	} else {
		m_AUTON_MODE++;
	}
	SmartDashboard::PutNumber("Auton Mode",m_AUTON_MODE);
}
