#ifndef _UTIL_H_
#define _UTIL_H_
#include <string>

/* XXX Fix port if needed */
#define PORT 6666

/* TODO: Add specific data and bool type that you want to send */ 
struct data
{
	/* For steering angle */
	bool isSteeringAngle;	
	float steeringAngle;

	/* for motor speed */
	bool isMotorSpeed;
	float motorSpeed;
};

#endif
