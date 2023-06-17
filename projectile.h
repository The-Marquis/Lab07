#pragma once

#include "position.h"

class Projectile
{
private:
	double mass;
	double radius;
	Position flightPath[10];
public:
	Projectile() { this->mass = 0.0; this->radius = 0.0; };
	void reset()
	{

	}
	void fire()
	{

	}
	void advance()
	{

	}
	void draw()
	{

	}
	bool flying()
	{
		return true;
	}

	//getters
	double getAltitude()
	{
		return 10.0;
	}
	Position getPosition()
	{
		Position position;
		return position;
	}
	double getFlightTime()
	{

	}
	double getFlightDistance()
	{

	}
	double getSpeed()
	{

	}
	double getCurrentTime()
	{

	}
	double getMass()
	{
		return mass;
	}
	double getRadius()
	{
		return radius;
	}

	//setters
	void setMass(double mass)
	{
		this->mass = mass;
	}
	void setRadius(double radius)
	{
		this->radius = radius;
	}
};