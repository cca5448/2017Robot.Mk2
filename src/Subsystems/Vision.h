#ifndef SUBS_VISION_H_
#define SUBS_VISION_H_

#include "WPILib.h"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

class Vision: public Subsystem
{
	private:
		//cs::AxisCamera cam1;
		//cs::AxisCamera cam2;
		//cs::VideoSink server;
		//cs::CvSink cvsink1;
		//cs::CvSink cvsink2;
		//int isCam1 = 1;
	public:
		Vision();
		void InitDefaultCommand();
		void MultiCamServer();
		void StartThread();
		void ToggleCamera();
};

#endif
