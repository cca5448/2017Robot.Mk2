#ifndef MAIN_OI_H_
#define MAIN_OI_H_

#include "WPILib.h"

class OI
{
	public:
		OI();
		double GetDriveAxis(bool left); //returns the axis to drive the robot
	private:
		//create joystick objects
		Joystick * driver_stick_l; //driver joystick left
		Joystick * driver_stick_r; //driver joystick right
		Joystick * oper_stick; //operator joystick

		//create buttons for control
		JoystickButton * climber_fwd;
		JoystickButton * climber_rev;
		JoystickButton * climber_stop;
		JoystickButton * auton_next; //switch to next auton
		JoystickButton * auton_prev; //switch to prev auton
};

#endif
