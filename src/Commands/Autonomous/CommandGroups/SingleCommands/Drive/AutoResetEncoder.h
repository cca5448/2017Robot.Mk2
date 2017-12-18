#ifndef CMDGRP_S_AUTORESETENCODER_H_
#define CMDGRP_S_AUTORESETENCODER_H_

#include "Commands/Command.h"
#include "WPILib.h"

class AutoResetEncoder: public Command
{
	private:
	public:
		AutoResetEncoder();
		void Initialize();
		void Execute();
		bool IsFinished();
		void End();
		void Interrupted();
};

#endif
