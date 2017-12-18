#ifndef CMDGRP_S_AUTODRIVETURNLEFT_H_
#define CMDGRP_S_AUTODRIVETURNLEFT_H_

#include "Commands/Command.h"
#include "WPILib.h"

class AutoDriveTurnLeft: public Command
{
	private:
		float m_TARGET_ANGLE;
	public:
		AutoDriveTurnLeft(float angle);
		void Initialize();
		void Execute();
		bool IsFinished();
		void End();
		void Interrupted();
};

#endif
