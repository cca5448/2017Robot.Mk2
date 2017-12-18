#ifndef SUBS_CLIMBER_H_
#define SUBS_CLIMBER_H_

#include "WPILib.h"

class Climber: public Subsystem
{
	private:
		VictorSP * climb_motor;
	public:
		Climber();
		void InitDefaultCommand();
		void StartClimberFwd();
		void StartClimberRev();
		void StopClimber();
		bool IsClimberRunning();
};

#endif
