#include "Autonomous.h"
#include "Robot.h"
//#include "CommandGroups/SimpleAuto.h"

#include "CommandGroups/SingleCommands/Drive/AutoDriveBackwards.h"
#include "CommandGroups/SingleCommands/Drive/AutoDriveForward.h"
#include "CommandGroups/SingleCommands/Drive/AutoDriveTurnLeft.h"
#include "CommandGroups/SingleCommands/Drive/AutoDriveTurnRight.h"
#include "CommandGroups/SingleCommands/Drive/AutoResetEncoder.h"
//#include "CommandGroups/Turn.h"
//#include "CommandGroups/StartShooter.h"
//#include "CommandGroups/Aim.h"
//#include "CommandGroups/FeedFuel.h"

#include "CommandGroups/FinishAuto.h"

//#include "CommandGroups/DriveToGear.h"

Autonomous::Autonomous(int mode)
{
	Requires(Robot::drivebase);
	m_AUTON_MODE = mode;
	SmartDashboard::PutNumber("Auton Mode",m_AUTON_MODE);

	switch (m_AUTON_MODE) {
		case 0: //do nothing
			SmartDashboard::PutString("Auton","Do Nothing");
			break;
		case 1: //drive to baseline
			SmartDashboard::PutString("Auton","Drive Backwards To Baseline");
			AddSequential(new AutoDriveBackwards(65));
			break;
		case 2: //left backwards turn left backwards to gear
			SmartDashboard::PutString("Auton","Left Backwards Turn Left Deliver Gear");
			AddSequential(new AutoDriveBackwards(90));
			AddSequential(new AutoDriveTurnRight(53));
			AddSequential(new AutoResetEncoder());
			AddSequential(new AutoDriveBackwards(24));
			break;
		case 3: //straight backwards to gear
			SmartDashboard::PutString("Auton","Straight Backwards Deliver Gear");
			AddSequential(new AutoDriveBackwards(82));
			break;
		case 4: //right backwards turn right backwards to gear
			SmartDashboard::PutString("Auton","Right Backwards Turn Right Deliver Gear");
			AddSequential(new AutoDriveBackwards(90));
			AddSequential(new AutoDriveTurnLeft(53));
			AddSequential(new AutoResetEncoder());
			AddSequential(new AutoDriveBackwards(24));
			break;
		case 5: //drive forward to baseline
			SmartDashboard::PutString("Auton","Drive forwards to Baseline");
			AddSequential(new AutoDriveForward(65));
			break;
		default: //do nothing
			SmartDashboard::PutString("Auton","Do Nothing (default)");
			break;
	}

	//Run SimpleAuto sequence
	//AddSequential(new SimpleAuto());

	//Drive to baseline, turn, aim, feed fuel
	//AddSequential(new DriveToBaseline(500));
	//AddSequential(new AutoDriveTurnLeft(75.0));
	//AddParallel(new StartShooter());
	//AddSequential(new Aim());
	//AddSequential(new FeedFuel());

	//Finish Autonomous
	AddSequential(new FinishAuto());
}
