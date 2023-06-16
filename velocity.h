#pragma once
/***********************************************************************
 * Header File:
 *    Velocity : Represents the velocity in the artillery simulation
 * Author:
 *    Garrett Badger
 * Summary:
 *    Everything about the velocity
 ************************************************************************/

#pragma once

#include "position.h"   // for Point
#include "uiDraw.h"
#include "direction.h"

 // forward declaration for the Velocity unit tests
class TestVelocity;

/***********************************************************
 * Velocity
 * The velocity class
 ***********************************************************/
class Velocity
{
public:
	Velocity() { this->dx = 0; this->dy = 0; };
	double getDX()
	{
		return this->dx;
	}
	double getDY()
	{
		return this->dy;
	}
	double getSpeed()
	{
		return speed;
	}
	Direction getDirection()
	{
		Direction direction;
		return direction;
	}
	void setDX(double dx)
	{
		this->dx = dx;
	}
	void setDY(double dy)
	{
		this->dy = dy;
	}
	void setDxDy(double dx, double dy)
	{
		this->dx = dx;
		this->dy = dy;
	}
	void setDirection(Direction direction)
	{
		
	}
	void setSpeed(double speed)
	{
		this->speed = speed;
	}
	void addDX(double dx)
	{
		this->dx += dx;
	}
	void addDY(double dy)
	{
		this->dy += dy;
	}
	void addV(Velocity velocity)
	{

	}
	void reverse()
	{
		this->dx = -1 * dx;
		this->dy = -1 * dy;
	}
private:
	double dx;
	double dy;
	double speed;
};