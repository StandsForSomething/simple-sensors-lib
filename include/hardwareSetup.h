#ifndef HARDWARESETUP_H_
#define HARDWARESETUP_H_

extern bool useRamp;

//////////
//motors//
////////////////////////////////////////////////////////////////
//this may be a bit confusing with an 8 motor drive. I made a //
//diagram showing the name of each motor and it's port number.//
//the slashes and backslashes represent the meccanum wheels.  //
//the real names used in the program are abreveiated, for     //
//example FLDrive is front left and LFdrive is left front.    //
////////////////////////////////////////////////////////////////
//       front left(8)---v           v-------front right(9)   //
//                     |\\\|       |///|                      //
//                     |---------------|                      //
//   left front(7)   \\|               |//   right front(2)   //
//                   \\|               |//                    //
//                   --|               |--                    //
//   left back(6)    //|               |\\   right back(3)    //
//                   //|_______________|\\                    //
//                     |///|       |\\\|                      //
//       back left(5)----^           ^-------back right(4)    //
////////////////////////////////////////////////////////////////

//motor structure
typedef struct motor
{
	int port;
	bool reversed;
}motor;

//the winch and punchers are assigned to the same port. this is becuase there are
//two different configurations for the robot, one with punchers and one a ramp
//that uses a two motor winch

//winch
extern motor winch1;      //port 1, not reversed
extern motor winch2;      //port 10, reversed

//punchers
extern motor puncher1;    //port 1, not reversed
extern motor puncher2;    //port 10, reversed

//right motors
extern motor RFDrive;     //port 2, reversed
extern motor RBDrive;     //port 3, reversed

//back motors
extern motor BRDrive;     //port 4, reversed
extern motor BLDrive;     //port 5, not reversed

//left motors
extern motor LBDrive;     //port 6, not reversed
extern motor LFDrive;     //port 7, not reversed

//front motors
extern motor FLDrive;     //port 8, not reversed
extern motor FRDrive;     //port 9, reversed

///////////
//sensors//
///////////

//well, technically DIGITAL_OUT isn't a sensor but whatever.
typedef enum sensorType {ANALOG, DIGITAL, DIGITAL_OUT}sensorType;

//sensor structure
typedef struct sensor
{
    int port;
    sensorType sensortype;
    bool reversed;
}sensor;

//digital
extern sensor powerExpandJumper;    //digital port 1, input, reversed
extern sensor configJumper;         //digital port 2, imput, reversed

//analog
extern sensor tileSelect;        //analog port 1, not reversed
extern sensor movementSelect;    //analog port 2, not reversed
extern sensor powerExpand;     //analog port 3, not reversed

//IME's
extern sensor RFenc;    //IME, I2C 0, not reversed
extern sensor RBenc;    //IME, I2C 1, not reversed
extern sensor BRenc;    //IME, I2C 2, not reversed
extern sensor BLenc;    //IME, I2C 3, not reversed
extern sensor LBenc;    //IME, I2C 4, not reversed
extern sensor LFenc;    //IME, I2C 5, not reversed
extern sensor FLenc;    //IME, I2C 6, not reversed
extern sensor FRenc;    //IME, I2C 7, not reversed

//definition for cortex pins
#define POWER_EXPAND_JUMP 1    //digital port 1
#define CONFIG_JUMP 2          //digital port 2

#define TILE_SELECT 13         //analog port 1
#define MOVE_SELECT 14         //analog port 2
#define POWER_EXPAND 15        //analog port 3


//function prototypes
extern void setMotor(struct motor theMotor, int speed);
extern int getSensor(struct sensor theSensor);
extern void setOutput(struct sensor theSensor, bool value);

#endif //HARDWARESETUP_H_