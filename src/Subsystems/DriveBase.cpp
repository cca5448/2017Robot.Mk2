#include <WPILib.h>
#include <CANTalon.h>
#include <ADXRS450_Gyro.h>
#include "DriveBase.h"
#include "Commands/DriveBase/TeleopTankDrive.h"
#include "../RobotMap.h"


DriveBase::DriveBase() : Subsystem("DriveBase")
{
	lf_motor = new CANTalon(MOT_DRV_LF);
	lr_motor = new CANTalon(MOT_DRV_LR);
	rf_motor = new CANTalon(MOT_DRV_RF);
	rr_motor = new CANTalon(MOT_DRV_RR);
	drive_gyro = new ADXRS450_Gyro();
}



void DriveBase::InitDefaultCommand()
{
	SetDefaultCommand(new TeleopTankDrive());
}

void DriveBase::DriveTank(double left_speed, double right_speed)
{
	lf_motor->Set(left_speed);
	lr_motor->Set(left_speed);
	rf_motor->Set(-right_speed);
	rr_motor->Set(-right_speed);
}

float DriveBase::ReturnEncoderDistance(float e1, float e2, float distance)
{
	lf_motor->SetFeedbackDevice(CANTalon::QuadEncoder); //tells left talon it has encoder
	rf_motor->SetFeedbackDevice(CANTalon::QuadEncoder); //tells right talon it has encoder
	//lf_motor->SetSensorDirection(true);
	//rf_motor->SetSensorDirection(true); See Talon SRX Software Reference section 7.4

	e1 = lf_motor->GetEncPosition() * -1; //sets e1 to left value
	e2 = rf_motor->GetEncPosition() * 1; //sets e2 to right value
	distance = e1;  //set distance to e1
	distance += e2; //add e2 encoder value
	distance /= 2; //divide by 2 to get the average
	SmartDashboard::PutNumber("Encoder Left",e1);
	SmartDashboard::PutNumber("Encoder Right",e2);
	SmartDashboard::PutNumber("Encoder Average",distance);
	SmartDashboard::PutNumber("Encoder Inches",ConvertEncoderToInches(distance));
	return distance;
}

float DriveBase::ConvertInchesToEncoder(float inches)
{
	inches /= 0.00525;
	return inches;
}

float DriveBase::ConvertEncoderToInches(float encUnits)
{
	encUnits *= 0.00525;
	return encUnits;
}

void DriveBase::ResetEncoderPosition()
{
	lf_motor->SetPosition(0); //set left to 0
	rf_motor->SetPosition(0); //set right to 0
}

float DriveBase::ReturnGyroAngle()
{
	SmartDashboard::PutNumber("Gyro Angle", drive_gyro->GetAngle());
	return drive_gyro->GetAngle(); //0 to 1.1?
}

void DriveBase::ResetGyro()
{
	int rval;
	drive_gyro->Reset();
	//increment gyro resets counter and display it in the dashboard
	rval = SmartDashboard::GetNumber("Gyro Resets",0);
	rval++;
	SmartDashboard::PutNumber("Gyro Resets", rval);
}

void DriveBase::CalibrateGyro()
{
	int cval;
	drive_gyro->Calibrate();
	//increment gyro calibrations counter and display it in the dashboard
	cval = SmartDashboard::GetNumber("Gyro Calibrations",0);
	cval++;
	SmartDashboard::PutNumber("Gyro Calibrations", cval);
	DriveBase::ResetGyro();
}

