#ifndef SUBS_VISION_H_
#define SUBS_VISION_H_

#include "WPILib.h"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

class Vision: public Subsystem
{
	private:

	public:
		Vision();
		void InitDefaultCommand();
		void FindGoal();
};

#endif
