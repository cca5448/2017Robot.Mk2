#ifndef CMD_STOPCLIMBER_H_
#define CMD_STOPCLIMBER_H_

#include "Commands/Command.h"
#include "WPILib.h"

class StopClimber: public Command
{
	public:
		StopClimber();
		void Initialize();
		void Execute();
		bool IsFinished();
		void End();
		void Interrupted();
};

#endif
