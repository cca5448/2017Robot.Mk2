#ifndef SUBS_DRIVEBASE_H_
#define SUBS_DRIVEBASE_H_

#include <ctre/Phoenix.h>
#include "WPILib.h"

class DriveBase: public Subsystem
{
	private:
		TalonSRX * lf_motor; //left front
		TalonSRX * lr_motor; //left rear
		TalonSRX * rf_motor; //right front
		TalonSRX * rr_motor; //right rear
		PigeonIMU * pidgey; //IMU
		enum { gyroCorrectOff, gyroCorrectIMU, gyroCorrectThrottle } driveStraight = gyroCorrectIMU; //This is how we correct for straight driving

		double kPgain = 0.04; /* percent throttle per degree of error */
		double kDgain = 0.0004; /* percent throttle per angular velocity dps */
		double kMaxCorrectionRatio = 0.30; /* cap corrective turning throttle to 30 percent of forward throttle */
		double driveTargetAngle = 0; //Holds the heading to maintain
		int debugPrintLoops = 0;
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
		double Ceiling(double value, double peak); //Returns the peak value if value is higher
		double MaxCorrection(double throttle, double scalor);
};

#endif
