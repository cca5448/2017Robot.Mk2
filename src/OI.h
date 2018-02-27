#ifndef MAIN_OI_H_
#define MAIN_OI_H_

#include "WPILib.h"

class OI
{
	public:
		OI();
		double GetThrottleAxis(); //returns the axis to drive the robot
		double GetSteerAxis(); //returns the axis to steer the robot
	private:
		//create joystick objects
		Joystick * driver_stick_throttle; //driver joystick left
		Joystick * driver_stick_steer; //driver joystick right
		Joystick * oper_stick; //operator joystick

		//create buttons for control
		JoystickButton * climber_up;
		JoystickButton * climber_down;
		JoystickButton * climber_stop;
		JoystickButton * camera_toggle; //switch camera view
		JoystickButton * auton_next; //switch to next auton
		JoystickButton * auton_prev; //switch to prev auton

		JoystickButton * shooter_btn; //raise or lower shooter
};

#endif
