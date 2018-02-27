#include "WPILib.h"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <Commands/Vision/StartCameraServer.h>
#include "Commands/Vision/CameraToggle.h"
#include "Vision.h"
#include "../RobotMap.h"

Vision::Vision() : Subsystem("Vision")
{
	CameraServer::GetInstance()->StartAutomaticCapture();
	CameraServer::GetInstance()->AddAxisCamera("Shooter Cam","10.54.48.10");
	CameraServer::GetInstance()->AddAxisCamera("Drive Cam","10.54.48.11");
/*
	cam1 = CameraServer::GetInstance()->AddAxisCamera("Driver Cam","10.54.48.10");
	cam2 = CameraServer::GetInstance()->AddAxisCamera("Shooter Cam","10.54.48.11");
	server = CameraServer::GetInstance()->GetServer();
	cam1.SetResolution(320,240); //320x240 or 640x480
	cam2.SetResolution(320,240);
	cvsink1 = new cs::CvSink("cam1cv");
	cvsink1.SetSource(cam1);
	cvsink1.SetEnabled(true);
	cvsink2 = new cs::CvSink("cam2cv");
	cvsink2.SetSource(cam2);
	cvsink2.SetEnabled(true);
*/
}

void Vision::InitDefaultCommand()
{
	SetDefaultCommand(new StartCameraServer());
}

void Vision::MultiCamServer()
{
	//cs::AxisCamera cam1 = CameraServer::GetInstance()->AddAxisCamera("Driver Cam","10.54.48.10");
	//cs::AxisCamera cam2 = CameraServer::GetInstance()->AddAxisCamera("Shooter Cam","10.54.48.11");
	//cs::VideoSink server = CameraServer::GetInstance()->GetServer();
	//cam1.SetResolution(320,240); //320x240 or 640x480
	//cam2.SetResolution(320,240);
	//cs::CvSink cvsink1 = new cs::CvSink("cam1cv");
	//cvsink1.SetSource(cam1);
	//cvsink1.SetEnabled(true);
	//cs::CvSink cvsink2 = new cs::CvSink("cam2cv");
	//cvsink2.SetSource(cam2);
	//cvsink2.SetEnabled(true);
	//cs::CvSink cvsink1 = new cs::CvSink("cam1cv");
	//cs::CvSink cvsink1;
	//cvsink1.SetSource(cam1);
	//cvsink1.SetEnabled(true);
	//cs::CvSink cvsink2 = new cs::CvSink("cam2cv");
	//cs::CvSink cvsink2;
	//cvsink2.SetSource(cam2);
	//cvsink2.SetEnabled(true);

/*
	cs::CvSource grayStream = CameraServer::GetInstance()->PutVideo("Gray",320,240);
	cv::Mat source;
	cv::Mat output;
	while(true) {
		cvsink2.GrabFrame(source);
		cvtColor(source, output, cv::COLOR_BGR2GRAY);
		grayStream.PutFrame(output);
	}
*/
}

void Vision::ToggleCamera()
{
	//cs::VideoSink server = CameraServer::GetInstance()->GetServer();
	//server.SetSource(cs::CvSource)
	//printf("toggle camera\n");
}

void Vision::StartThread()
{
	//std::thread visionThread(Vision->MultiVisionThread);
	//visionThread.detach();
}


