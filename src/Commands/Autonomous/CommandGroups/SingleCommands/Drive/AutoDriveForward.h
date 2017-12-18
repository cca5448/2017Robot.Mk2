#ifndef CMDGRP_S_AUTODRIVEFORWARD_H_
#define CMDGRP_S_AUTODRIVEFORWARD_H_

#include "Commands/Command.h"
#include "WPILib.h"

class AutoDriveForward: public Command
{
	private:
		int m_TARGET_DISTANCE;
	public:
		AutoDriveForward(int distance);
		void Initialize();
		void Execute();
		bool IsFinished();
		void End();
		void Interrupted();
};

#endif
