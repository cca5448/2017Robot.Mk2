#ifndef CMD_STARTCLIMBERREV_H_
#define CMD_STARTCLIMBERREV_H_

#include "Commands/Command.h"
#include "WPILib.h"

class StartClimberRev: public Command
{
	public:
		StartClimberRev();
		void Initialize();
		void Execute();
		bool IsFinished();
		void End();
		void Interrupted();
};

#endif
