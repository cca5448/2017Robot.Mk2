#ifndef CMD_PREVAUTON_H_
#define CMD_PREVAUTON_H_

#include "Commands/Command.h"
#include "WPILib.h"

class PrevAuton: public Command
{
	public:
		PrevAuton();
		void Initialize();
		void Execute();
		bool IsFinished();
		void End();
		void Interrupted();
};

#endif
