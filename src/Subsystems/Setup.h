#ifndef SUBS_SETUP_H_
#define SUBS_SETUP_H_

#include "WPILib.h"

class Setup: public Subsystem
{
    private:
		int m_AUTON_MODE;
	public:
		Setup();
		void InitDefaultCommand();
		int ReturnAutonMode();
		void NextAutonMode();
		void PrevAutonMode();
};

#endif
