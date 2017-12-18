#include "SimpleDrive.h"
#include "../SingleCommands/Drive/AutoDriveForward.h"
#include "../SingleCommands/Drive/AutoDriveBackwards.h"

SimpleDrive::SimpleDrive()
{
	AddSequential(new AutoDriveBackwards(93));
}
