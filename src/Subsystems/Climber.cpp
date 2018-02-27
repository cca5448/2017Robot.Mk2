#include "WPILib.h"
#include "Climber.h"
#include "../RobotMap.h"

Climber::Climber() : Subsystem("Climber")
{
	climb_motor = new VictorSP(MOT_CLIMB);
}

void Climber::InitDefaultCommand()
{
	//SetDefaultCommand(new Climb());
}

void Climber::StartClimberFwd()
{
	//SmartDashboard::PutBoolean(SDB_CLIMB_LED_ID,true);
	//feed_motor->Set(Robot::setup->SDB_ReturnFeederSpeed());

	//if (!Robot::shooter->IsShooterRunning()) {
		//Robot::shooter->StartShooter(MOT_SHOOTER_SPEED_DEF);
		//frc::Wait(1);
	//}
	if (IsClimberRunning() && climb_motor->Get() > 0) {
		climb_motor->Set(-MOT_CLIMB_SPEED_DEF);
	} else {
		climb_motor->Set(MOT_CLIMB_SPEED_DEF);
	}
}

void Climber::StartClimberRev()
{
	//SmartDashboard::PutBoolean(SDB_CLIMB_LED_ID,true);
	//feed_motor->Set(-Robot::setup->SDB_ReturnFeederSpeed());
	//if (!Robot::shooter->IsShooterRunning()) {
		//Robot::shooter->StartShooter(MOT_SHOOTER_SPEED_DEF);
		//frc::Wait(1);
	//}
	if (IsClimberRunning() && climb_motor->Get() < 0) {
		climb_motor->Set(MOT_CLIMB_SPEED_DEF);
	} else {
		climb_motor->Set(-MOT_CLIMB_SPEED_DEF);
	}
}

void Climber::StopClimber()
{
	//SmartDashboard::PutBoolean(SDB_CLIMB_LED_ID,false);
	climb_motor->StopMotor(); //stop feed motor
}

bool Climber::IsClimberRunning()
{
	if (climb_motor->Get() != 0) return true;
	return false;
}
