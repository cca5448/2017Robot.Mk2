#ifndef CMD_TELEOPTANKDRIVE_H_
#define CMD_TELEOPTANKDRIVE_H_

#include "Commands/Command.h"
#include "WPILib.h"

class TeleopTankDrive: public Command
{
	public:
		TeleopTankDrive();
		void Initialize();
		void Execute();
		bool IsFinished();
		void End();
		void Interrupted();
};

#endif