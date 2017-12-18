#ifndef SUBS_DRIVEBASE_H_
#define SUBS_DRIVEBASE_H_

#include <CANTalon.h>
#include <ADXRS450_Gyro.h>
#include "WPILib.h"

class DriveBase: public Subsystem
{
	private:
		CANTalon * lf_motor; //left front
		CANTalon * lr_motor; //left rear
		CANTalon * rf_motor; //right front
		CANTalon * rr_motor; //right rear
		ADXRS450_Gyro * drive_gyro; //gyro
	public:
		DriveBase();
		void InitDefaultCommand();
		void DriveTank(double left_speed, double right_speed); //drives the robot
		float ReturnEncoderDistance(float e1, float e2, float distance); //returns the distance
		float ConvertInchesToEncoder(float inches); //converts inches to encoder distance
		float ConvertEncoderToInches(float encUnits); //converts encoder distance to inches
		void ResetEncoderPosition(); //resets encoders
		float ReturnGyroAngle(); //returns the angle
		void ResetGyro(); //resets the gyro
		void CalibrateGyro(); //calibrates the gyro while robot is idle
};

#endif
