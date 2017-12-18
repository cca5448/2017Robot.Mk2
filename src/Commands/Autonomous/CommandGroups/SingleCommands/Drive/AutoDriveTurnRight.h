#ifndef CMDGRP_S_AUTODRIVETURNRIGHT_H_
#define CMDGRP_S_AUTODRIVETURNRIGHT_H_

#include "Commands/Command.h"
#include "WPILib.h"

class AutoDriveTurnRight: public Command
{
	private:
		float m_TARGET_ANGLE;
	public:
		AutoDriveTurnRight(float angle);
		void Initialize();
		void Execute();
		bool IsFinished();
		void End();
		void Interrupted();
};

#endif
