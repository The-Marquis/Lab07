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
	friend::TestVelocity;

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
		speed = sqrt((dx * dx) + (dy * dy));
		return speed;
	}
	Direction* getDirection()
	{
		
		return this->d;
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
	void setDirection(Direction *direction)
	{
		this->d = direction;
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
		this->dx = velocity.dx;
		this->dy = velocity.dy;
	}
	void reverse()
	{
		this->dx = dx * -1;
		this->dy = dy * -1;
	}
	double computeVerticalComponent(double a, double total)
	{
		double y = cos(a) * total;
		return y;
	}
	double computeHorizontalComponent(double a, double total)
	{
		double x = sin(a) * total;
		return x;
	}
	double computeVelocity(double v, double a, double t)
	{
		double newV = v + a * t;
		return newV;
	}
private:
	double dx;
	double dy;
	double speed;
	Direction *d;
};