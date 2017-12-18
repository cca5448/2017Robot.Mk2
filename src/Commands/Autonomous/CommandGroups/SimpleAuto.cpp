#include "SimpleAuto.h"
#include "SimpleAuto/SimpleDrive.h"
#include "SimpleAuto/SimpleTurn.h"

SimpleAuto::SimpleAuto(){
	SmartDashboard::PutString("Auton","SimpleAuto");
	AddSequential(new SimpleDrive());
	AddSequential(new SimpleTurn());
}
