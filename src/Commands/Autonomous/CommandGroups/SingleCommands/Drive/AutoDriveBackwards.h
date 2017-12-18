#ifndef CMDGRP_S_AUTODRIVEBACKWARDS_H_
#define CMDGRP_S_AUTODRIVEBACKWARDS_H_

#include "Commands/Command.h"
#include "WPILib.h"

class AutoDriveBackwards: public Command
{
	private:
		int m_TARGET_DISTANCE;
	public:
		AutoDriveBackwards(int distance);
		void Initialize();
		void Execute();
		bool IsFinished();
		void End();
		void Interrupted();
};

#endif
