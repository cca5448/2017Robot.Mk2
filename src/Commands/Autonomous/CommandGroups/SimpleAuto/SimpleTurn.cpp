#include "../SingleCommands/Drive/AutoDriveTurnLeft.h"
#include "../SingleCommands/Drive/AutoDriveTurnRight.h"
#include "SimpleTurn.h"

SimpleTurn::SimpleTurn()
{
	AddSequential(new AutoDriveTurnLeft(90.0));
//	AddSequential(new AutoDriveTurnRight(180.0));
//	AddSequential(new AutoDriveTurnLeft(90.0));
}
