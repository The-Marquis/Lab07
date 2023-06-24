#pragma once

#include "position.h"
#include "velocity.h"
#include "direction.h"
#include <vector>
using namespace std;

class Projectile
{
private:
	double mass;
	double radius;
	vector<Position> flightPathPosition{};
	vector<Velocity> flightPathVelocity{};
	vector<double> flightPathTime{0.0};
public:
	Projectile() 
	{ 
		this->mass = 0.0; 
		this->radius = 0.0; 
		Position p;
		this->flightPathPosition.push_back(p); 
		Velocity v;
		this->flightPathVelocity.push_back(v);
	};
	void reset()
	{
		flightPathPosition.clear();
		flightPathVelocity.clear();
		flightPathTime.clear();

		Position p;
		Velocity v;
		flightPathPosition.push_back(p);
		flightPathVelocity.push_back(v);
		flightPathTime.push_back(0.0);
	}
	void fire()
	{

	}
	void advance()
	{
		Position pt = flightPathPosition.back();
		Velocity v = flightPathVelocity.back();
		double t = flightPathTime.back();
		double speed = v.getSpeed();
		int altitude = pt.getMetersY();

		// modify velocity to handle wind resistance
		double density = densityFromAltitude(altitude);
		double dragCoefficient = dragFromSpeed(speed, altitude);
		double windResistance = forceFromDrag(density, dragCoefficient, radius, speed);
		double accelerationDrag = accelerationFromForce(windResistance, mass);
		//double velocityWind = velocityFromAcceleration(accelerationDrag, 0.5), v.getDirection();
		// velocityWind.reverse();
		// v.addV(velocityWind);

		// modify velocity to handle gravity
		double accelerationGravity = gravityFromAltitude(altitude);
		double velocityGravity = velocityFromAcceleration(accelerationGravity, 0.5) ;
		// v.addV(velocityGravity);

		// inertia
		pt.addMetersX(velocityFromAcceleration(v.getDX(), 0.5));
		pt.addMetersY(velocityFromAcceleration(v.getDY(), 0.5));

		// add to back of flight path
		flightPathPosition.push_back(pt);
		flightPathVelocity.push_back(v);
		flightPathTime.push_back(t + 0.5);

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
		return flightPathTime.back() - flightPathTime.front();
	}
	double getFlightDistance()
	{
		return flightPathPosition.back().getMetersX() - flightPathPosition.front().getMetersX();
	}
	double getSpeed()
	{
		return flightPathVelocity.back().getSpeed();
	}
	double getCurrentTime()
	{
		return flightPathTime.back();
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

	// physics
	double densityFromAltitude(double a)
	{

	}
	double gravityFromAltitude(double a)
	{

	}
	double dragFromSpeed(double s, double a)
	{

	}
	double velocityFromAcceleration(double acc, double i)
	{

	}
	double forceFromDrag(double d, double drag, double r, double s)
	{

	}
	double accelerationFromForce(double wr, double m)
	{

	}


};