#include <math.h>
#include "OI.h"
#include "RobotMap.h"
#include "Commands/Climber/StartClimberFwd.h"
#include "Commands/Climber/StartClimberRev.h"
#include "Commands/Climber/StopClimber.h"

//array for the controller dead zone this makes it slightly ramp up at it gets to the working zone
const char inputShape[255] = {
0,1,3,4,5,6,7,9,10,11,12,13,15,16,17,18,19,21,22,23,24,25,27,28,29,30,31,
33,34,35,36,37,38,40,41,42,43,44,46,47,48,49,50,52,53,54,55,56,58,59,60,61,
62,64,65,66,67,68,70,71,72,73,74,76,77,78,79,80,82,83,84,85,86,88,89,90,91,
92,94,95,96,97,98,98,99,99,100,101,102,103,104,105,106,107,108,109,110,111,
111,113,113,115,115,116,116,117,117,118,118,119,119,120,120,121,121,122,122,
123,123,124,124,125,125,126,126,127,127,
127,127,128,128,129,129,130,130,131,131,132,132,133,133,134,134,135,135,136,
136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,
155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,
174,175,176,177,178,179,179,180,181,182,183,184,186,187,188,189,190,192,193,
194,195,196,198,199,200,201,202,204,205,206,207,208,210,211,212,213,214,216,
217,218,219,220,221,223,224,225,226,227,229,230,231,232,233,235,236,237,238,
239,241,242,243,244,245,247,248,249,250,251,253,254,255};

//create deadzone for axis
float DeadZone(float uVal)
{
	//if (uVal >= -JOYSTICK_DEADZONE && uVal <= JOYSTICK_DEADZONE) {
	//	return 0.0;
	//}
	//return uVal;
	if (uVal >= -JOYSTICK_DEADZONE && uVal <= JOYSTICK_DEADZONE) {
		return 0.0;
	}
	return uVal;
}

float NewDeadZone(float uval)
{
	float f_absval, f_offset, f_uval, f_pow;
	float invert = 1.0;
	if (uval < 0) invert = -1.0;
	f_absval = fabs(uval);
	//SmartDashboard::PutNumber("f_absval",f_absval);
	f_offset = 1+JOYSTICK_DEADZONE;
	//SmartDashboard::PutNumber("f_offset",f_offset);
	f_uval = f_absval;
	f_uval *= f_offset;
	//SmartDashboard::PutNumber("f_uval1",f_uval);
	f_uval -= JOYSTICK_DEADZONE;
	//SmartDashboard::PutNumber("f_uval2",f_uval);
	f_pow = f_offset * JOYSTICK_RAMP_POWER;
	//SmartDashboard::PutNumber("f_pow",f_pow);
	f_uval = pow(f_uval,f_pow);
	//SmartDashboard::PutNumber("f_uval3",f_uval);
	f_uval *= invert;
	SmartDashboard::PutNumber("uval",f_uval);
	return f_uval;

	/*
	 * https://www.desmos.com/calculator
	 * y=(xn-a)^mn //formula for speed ramp
	 * m=1.5 //ramp power of 1.5 (normal 1.1-1.8)
	 * a=0.3 //deadzone of 0.3
	 * n=1+a (multiplier to account for dead zone)
	 */
}

float InputShape(float userValue)
{
	double iUserValue;
	iUserValue = (double)userValue * 127;
	iUserValue += 127;
	//iUserValue = inputShape[iUserValue];
	SmartDashboard::PutNumber("iUserValue",iUserValue);
	userValue = iUserValue - 127;
	userValue /= 127;
	return userValue;
}

OI::OI()
{
	//constants are from RobotMap.h
	//joysticks
	driver_stick_l = new Joystick(JOY_DRIVE_L);
	driver_stick_r = new Joystick(JOY_DRIVE_R);
	oper_stick = new Joystick(JOY_OPER);

	//buttons to control bot
	climber_fwd = new JoystickButton(oper_stick,BTN_CLIMB_FWD);
	climber_rev = new JoystickButton(oper_stick,BTN_CLIMB_REV);
	climber_stop = new JoystickButton(oper_stick,BTN_CLIMB_STOP);
	auton_next = new JoystickButton(oper_stick,BTN_AUTON_NEXT);
	auton_prev = new JoystickButton(oper_stick,BTN_AUTON_PREV);

	climber_fwd->ToggleWhenPressed(new StartClimberFwd());
	climber_rev->ToggleWhenPressed(new StartClimberRev());
	climber_stop->ToggleWhenPressed(new StopClimber());
	//auton_next->ToggleWhenPressed(new NextAuton()); //Next Auton Mode
	//auton_prev->ToggleWhenPressed(new PrevAuton()); //Prev Auton Mode
}

//method will return the drive axis
double OI::GetDriveAxis(bool left){

	float m_right = NewDeadZone(driver_stick_r->GetRawAxis(JOY_DRV_AXIS_R));
	SmartDashboard::PutNumber("Right",m_right);
	float m_left = NewDeadZone(driver_stick_l->GetRawAxis(JOY_DRV_AXIS_L));
	SmartDashboard::PutNumber("Left",m_left);

	if(left){
		return -(InputShape(NewDeadZone(driver_stick_l->GetRawAxis(JOY_DRV_AXIS_L))));
	} else {
		return -(InputShape(NewDeadZone(driver_stick_r->GetRawAxis(JOY_DRV_AXIS_R))));
	}
}
//left = OI::GetDriveAxis(true)  // returns non-inverted value of left joystick
//right = OI::GetDriveAxis(false)  //returns inverted value of right joystick

