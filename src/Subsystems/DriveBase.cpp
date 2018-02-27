#include <WPILib.h>
#include <ctre/Phoenix.h>
#include "DriveBase.h"
#include "Commands/DriveBase/TeleopTankDrive.h"
#include "../RobotMap.h"


DriveBase::DriveBase() : Subsystem("DriveBase")
{
	lf_motor = new TalonSRX(MOT_DRV_LF);
	lr_motor = new TalonSRX(MOT_DRV_LR);
	rf_motor = new TalonSRX(MOT_DRV_RF);
	rr_motor = new TalonSRX(MOT_DRV_RR);
	pidgey = new PigeonIMU(IMU_CAN_ID);
}



void DriveBase::InitDefaultCommand()
{
	SetDefaultCommand(new TeleopTankDrive());
}

void DriveBase::DriveTank(double throttle, double steer)
{
	//TODO differential throttle based on steer
	//0 steer is full left
	//127 steer is neutral (straight)
	//255 steer is full right

	/*  Starting to get code for cheezy drive from team 254.
	 *  They have java example that could be adapted at
	 *  https://www.chiefdelphi.com/forums/showthread.php?t=116660&highlight=cheesy+drive
	 * if (straight) {
	 *   return (getLeftEncoderDistance() + getRightEncoderDistance()) / 2.0;
	 * } else {
     *   return getGyroAngle();
     * }
	*/

	//lf_motor->Set(throttle);
	//lr_motor->Set(throttle);
	//rf_motor->Set(-throttle);
	//rr_motor->Set(-throttle);

	float left = throttle - steer;
	float right = throttle + steer;
	left = Ceiling(left, 1.0);
	right = Ceiling(right, 1.0);

	if (++debugPrintLoops > 30) {
		debugPrintLoops = 0;
		printf("------------------------------\n", throttle);
		printf("throttle: %f\n", throttle);
		printf("steer: %f\n", steer);
		printf("left: %f\n", left);
		printf("right: %f\n", right);
	}

	/* right side motors need to drive negative to move robot forward */
	lf_motor->Set(ControlMode::PercentOutput, left);
	lr_motor->Set(ControlMode::PercentOutput, left);
	rf_motor->Set(ControlMode::PercentOutput, -1. * right);
	rr_motor->Set(ControlMode::PercentOutput, -1. * right);

}

double DriveBase::Ceiling(double value, double peak)
{
	if (value < -peak)
		return -peak;
	if (value > +peak)
		return +peak;
	return value;
}

float DriveBase::ReturnEncoderDistance(float e1, float e2, float distance)
{
	//lf_motor->SetFeedbackDevice(TalonSRX::QuadEncoder); //tells left talon it has encoder
	//rf_motor->SetFeedbackDevice(TalonSRX::QuadEncoder); //tells right talon it has encoder

	////lf_motor->SetSensorDirection(true);
	////rf_motor->SetSensorDirection(true); See Talon SRX Software Reference section 7.4

	//e1 = lf_motor->GetEncPosition() * -1; //sets e1 to left value
	//e2 = rf_motor->GetEncPosition() * 1; //sets e2 to right value
	//distance = e1;  //set distance to e1
	//distance += e2; //add e2 encoder value
	//distance /= 2; //divide by 2 to get the average
	//SmartDashboard::PutNumber("Encoder Left",e1);
	//SmartDashboard::PutNumber("Encoder Right",e2);
	//SmartDashboard::PutNumber("Encoder Average",distance);
	//SmartDashboard::PutNumber("Encoder Inches",ConvertEncoderToInches(distance));
	//return distance;
	return 0;
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
	//lf_motor->SetPosition(0); //set left to 0
	//rf_motor->SetPosition(0); //set right to 0
}

float DriveBase::ReturnGyroAngle()
{
	//SmartDashboard::PutNumber("Gyro Angle", drive_gyro->GetAngle());
	//return drive_gyro->GetAngle(); //0 to 1.1?
	return 0.0;
}

void DriveBase::ResetGyro()
{
	pidgey->SetFusedHeading(0.0, 10); /* reset heading, angle measurement wraps at plus/minus 23,040 degrees (64 rotations) */
	driveStraight = gyroCorrectIMU;

	printf("Gyro has been reset\n");
	//SmartDashboard::PutNumber("Gyro Resets", rval);
}

void DriveBase::CalibrateGyro()
{
	//int cval;
	//drive_gyro->Calibrate();
	////increment gyro calibrations counter and display it in the dashboard
	//cval = SmartDashboard::GetNumber("Gyro Calibrations",0);
	//cval++;
	//SmartDashboard::PutNumber("Gyro Calibrations", cval);
	//DriveBase::ResetGyro();
}

double DriveBase::MaxCorrection(double forwardThrot, double scalor) {
	/* make it positive */
	if (forwardThrot < 0) {
		forwardThrot = -forwardThrot;
	}
	/* max correction is the current forward throttle scaled down */
	forwardThrot *= scalor;
	/* ensure caller is allowed at least 10% throttle,
	 * regardless of forward throttle */
	if (forwardThrot < 0.10)
		return 0.10;
	return forwardThrot;
}
