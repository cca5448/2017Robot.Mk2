#ifndef CMD_STARTCLIMBERFWD_H_
#define CMD_STARTCLIMBERFWD_H_

#include "Commands/Command.h"
#include "WPILib.h"

class StartClimberFwd: public Command
{
	public:
		StartClimberFwd();
		void Initialize();
		void Execute();
		bool IsFinished();
		void End();
		void Interrupted();
};

#endif
