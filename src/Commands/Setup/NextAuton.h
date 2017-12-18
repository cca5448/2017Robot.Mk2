#ifndef CMD_NEXTAUTON_H_
#define CMD_NEXTAUTON_H_

#include "Commands/Command.h"
#include "WPILib.h"

class NextAuton: public Command
{
	public:
		NextAuton();
		void Initialize();
		void Execute();
		bool IsFinished();
		void End();
		void Interrupted();
};

#endif
