#include "WPILib.h"
//#include <SmartDashboard/SendableChooser.h>
#include "Robot.h"

#include "Commands/Autonomous/Autonomous.h"

//Set all the subsystems to null
OI * Robot::oi = NULL;
Climber * Robot::climber = NULL;
DriveBase * Robot::drivebase = NULL;
Vision * Robot::vision = NULL;
Air * Robot::air = NULL;
Setup * Robot::setup = NULL;

void Robot::RobotInit(){

	//Create new objects of subsystems
	oi = new OI();
	climber = new Climber();
	drivebase = new DriveBase();
	vision = new Vision();
	air = new Air();
	setup = new Setup();

/*
	//setup auton drop downs
	autonchooser = new SendableChooser<Command *>();
	autonchooser->AddDefault("Do Nothing",new Autonomous(0));
	autonchooser->AddObject("Drive to Baseline",new Autonomous(1));
	autonchooser->AddObject("Left back turn left gear deliver",new Autonomous(2));
	autonchooser->AddObject("Straight back gear deliver",new Autonomous(3));
	autonchooser->AddObject("Right back turn right gear deliver",new Autonomous(4));
	SmartDashboard::PutData("Auto Selector", autonchooser);
*/

	//other stuff
	//lw = LiveWindow::GetInstance();
//	autoncommand = (Command *) autonchooser->GetSelected();
	int mode = (int) SmartDashboard::GetNumber("DB/Slider 3",0);
	autoncommand = new Autonomous(mode);
	drivebase->CalibrateGyro();
	drivebase->ResetEncoderPosition();

}

void Robot::AutonomousInit(){
	drivebase->ResetEncoderPosition();
	int mode = (int) SmartDashboard::GetNumber("DB/Slider 3",0);
	autoncommand = new Autonomous(mode);
	autoncommand->Start();
}

void Robot::AutonomousPeriodic(){
	Scheduler::GetInstance()->Run(); //continually run the scheduler during auton
}

void Robot::TeleopInit(){
	autoncommand->Cancel();
	drivebase->ResetGyro();
}

void Robot::TeleopPeriodic(){
	Scheduler::GetInstance()->Run(); //continually run the scheduler during teleop
}

void Robot::TestPeriodic(){
	//lw->Run(); //runs the livewindow during test
}

void Robot::DisabledPeriodic(){
	Scheduler::GetInstance()->Run(); //continually run the scheduler during disabled
	//lw->Run(); //runs the livewindow during test
}

START_ROBOT_CLASS(Robot);
