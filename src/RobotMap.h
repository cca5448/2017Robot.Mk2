/*
* RobotMap defines motor and sensor ports and buttons/axis for the robot.
* This is for ease of use and to abstract the functions from the io names
*/

#ifndef ROBOTMAP_H_
#define ROBOTMAP_H_

//Robot Constants for decision making
static const float GYRO_KP = 0.03;
const unsigned short AUTON_MODE_MAX = 3;
const float AUTON_DRIVE_SPEED = 0.25; //speed to drive in auton mode
const float AUTON_TURN_SPEED = 0.25;
const float JOYSTICK_DEADZONE = 0.35;
const float JOYSTICK_RAMP_POWER = 1.1; //speed ramp power

//Gyro Code http://first.wpi.edu/FRC/roborio/release/docs/cpp/classfrc_1_1ADXRS450__Gyro.html

//CAN IDs - DriveBase
const unsigned short MOT_DRV_LF			= 2; //Speed Controller 1 is Left Front
const unsigned short MOT_DRV_LR			= 1; //Speed Controller 2 is Left Rear
const unsigned short MOT_DRV_RF			= 3; //Speed Controller 3 is Right Front
const unsigned short MOT_DRV_RR			= 4; //Speed Controller 4 is Right Rear

//climber Motors
const unsigned short MOT_CLIMB		= 0; //PWM Pin for Climber
const unsigned short MOT_CLIMB_SPEED_DEF		= 1.0; //Speed of Climber
const std::string SDB_CLIMB_SPEED_CTRL_ID = "DB/Slider 2"; //Dashboard ID of Climberbutton and led
const std::string SDB_CLIMB_BTN_ID		= "DB/Button 2";
const std::string SDB_CLIMB_LED_ID		= "DB/LED 2";

//Joysticks
const unsigned short JOY_DRIVE_L		= 0; //USB Port Driver Joystick left
const unsigned short JOY_DRIVE_R		= 1; //USB Port DRiver Joystick right
const unsigned short JOY_OPER			= 1; //USB Port for Operator Joystick

//Sensors
const unsigned short GYRO_1				= 0; //SPI Port for Gyro 1

//Driver Stick
const unsigned short JOY_DRV_AXIS_L		= 1; //Axis for Left Tank Drive
const unsigned short JOY_DRV_AXIS_R		= 1; //Axis for Right Tank Drive

//Buttons on oper stick
const unsigned short BTN_CLIMB_FWD		= 1; //forward climber
const unsigned short BTN_CLIMB_REV		= 2; //reverse climber
const unsigned short BTN_CLIMB_STOP		= 7; //stop climber
const unsigned short BTN_AUTON_1 = 1; //Auton 1
const unsigned short BTN_AUTON_2 = 2; //Auton 2
const unsigned short BTN_AUTON_3 = 3; //Auton 3
const unsigned short BTN_AUTON_4 = 4; //Auton 4
const unsigned short BTN_AUTON_5 = 5; //Auton 5
const unsigned short BTN_AUTON_NEXT	= 7; //Button for Auton Next
const unsigned short BTN_AUTON_PREV	= 6; //Button for Auton Prev

#endif
