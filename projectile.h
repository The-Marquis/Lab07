#pragma once

#include "position.h"
#include "velocity.h"
#include "direction.h"
#include "uiDraw.h"  
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

class Projectile
{
private:
	double mass;
	double radius;
	vector<Position> flightPathPosition{};
	vector<Velocity> flightPathVelocity{};
	vector<double> flightPathTime{0.0};
	ogstream gout;
	
public:
	Projectile() 
	{ 
		this->mass = 46.7; 
		this->radius = 77.445; 
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
	void fire(double angle)
	{
		Velocity v;
		v.setDY(v.computeVerticalComponent(angle, 827.0));
		v.setDX(v.computeHorizontalComponent(angle, 827.0));
		this->flightPathVelocity.push_back(v);
	}
	void advance()
	{
		Position pt = flightPathPosition.back();
		Velocity v = flightPathVelocity.back();
		double t = flightPathTime.back();
		double speed = v.getSpeed();
		double altitude = pt.getMetersY();

		// modify velocity to handle wind resistance
		double density = densityFromAltitude(altitude);
		double dragCoefficient = dragFromSpeed(speed, altitude);
		double windResistance = forceFromDrag(density, dragCoefficient, radius, speed);
		double accelerationDrag = accelerationFromForce(windResistance, mass);
		double velocityWind = velocityFromAcceleration(accelerationDrag, 0.5);
		// velocityWind.reverse();
		// v.addV(velocityWind);

		// modify velocity to handle gravity
		double accelerationGravity = gravityFromAltitude(altitude);
		double velocityGravity = velocityFromAcceleration(accelerationGravity, 0.5);
		//v.addV(velocityGravity);

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
		for (int i = 0; i < flightPathPosition.size(); i++)
			gout.drawProjectile(flightPathPosition[i], 0.5 * (double)i);
	}
	bool flying()
	{
		return true;
	}

	//getters
	double getAltitude()
	{
		return flightPathPosition.back().getMetersY();
	}
	Position getPosition()
	{
		return flightPathPosition.back();
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
	struct TableEntry 
	{
		double altitude;
		double returnValue;
	};

	double densityFromAltitude(double a)
	{
		vector<TableEntry> densityTable = {
			{0, 1.2250000},
			 {1000, 1.1120000},
			{2000, 1.0070000},
			{3000, 0.9093000},
			{4000, 0.8194000},
			{5000, 0.7364000},
			{6000, 0.6601000},
			{7000, 0.5900000},
			{8000, 0.5258000},
			{9000, 0.4671000},
			{10000, 0.4135000},
			{15000, 0.1948000},
			{20000, 0.0889100},
			{25000, 0.0400800},
			{30000, 0.0184100},
			{40000, 0.0039960},
			{50000, 0.0010270},
			{60000, 0.0003097},
			{70000, 0.0000828},
			{80000, 0.0000185}
		};

		int i;
		for (i = 0;
			i < 18;
			i++)
		{
			if (a == densityTable[i].altitude)
			{
				return densityTable[i].returnValue;
			}
			else if (a > densityTable[i].altitude)
			{
				return computeLinearInterpolation(a, densityTable[i].altitude, densityTable[i].returnValue, densityTable[i + 1].altitude, densityTable[i + 1].returnValue);
			}
		}


	}
	double gravityFromAltitude(double a)
	{
		vector<TableEntry> gravityTable = {
		{0, 9.807},
		{1000, 9.804},
		{2000, 9.801},
		{3000, 9.797},
		{4000, 9.794},
		{5000, 9.791},
		{6000, 9.788},
		{7000, 9.785},
		{8000, 9.782},
		{9000, 9.779},
		{10000, 9.776},
		{15000, 9.761},
		{20000, 9.745},
		{25000, 9.730}
		};

		int i;
		for (i = 0;
			i < 12;
			i++)
		{
			if (a == gravityTable[i].altitude)
			{
				return gravityTable[i].returnValue;
			}
			else if (a > gravityTable[i].altitude)
			{
				return computeLinearInterpolation(a, gravityTable[i].altitude, gravityTable[i].returnValue, gravityTable[i + 1].altitude, gravityTable[i + 1].returnValue);
			}
		}

	}
	double dragFromSpeed(double s, double a)
	{
		vector<TableEntry> dragTable = {
		{0.0, 0.000},
		{0.5, 0.1659},
		{0.7, 0.2039},
		{0.89, 0.2597},
		{0.92, 0.301},
		{0.96, 0.3287},
		{0.98, 0.4002},
		{1.0, 0.4258},
		{1.02, 0.4335},
		{1.06, 0.4483},
		{1.24, 0.4064},
		{1.53, 0.3663},
		{1.99, 0.2297},
		{2.87, 0.2297},
		{2.89, 0.2306},
		{5.0, 0.2656}
		};

		int i;
		for (i = 0;
			i < 14;
			i++)
		{
			if (a == dragTable[i].altitude)
			{
				return dragTable[i].returnValue;
			}
			else if (a > dragTable[i].altitude)
			{
				return computeLinearInterpolation(a, dragTable[i].altitude, dragTable[i].returnValue, dragTable[i + 1].altitude, dragTable[i + 1].returnValue);
			}
		}
	}
	double machFromSpeed(double v, double a)
	{
		vector<TableEntry> soundTable = {
		{0, 340},
		{1000, 336},
		{2000, 332},
		{3000, 328},
		{4000, 324},
		{5000, 320},
		{6000, 316},
		{7000, 312},
		{8000, 308},
		{9000, 303},
		{10000, 299},
		{15000, 295},
		{20000, 295},
		{25000, 295},
		{30000, 305},
		{40000, 324}
		};
		int i;
		double speedOfSound;
		for (i = 0;
			i < 14;
			i++)
		{
			if (a == soundTable[i].altitude)
			{
				speedOfSound = soundTable[i].returnValue;
			}
			else if (a > soundTable[i].altitude)
			{
				speedOfSound = computeLinearInterpolation(a, soundTable[i].altitude, soundTable[i].returnValue, soundTable[i + 1].altitude, soundTable[i + 1].returnValue);
			}
		}

		double mach = v / speedOfSound;
		return mach;
	}

	double velocityFromAcceleration(double acc, double t)
	{
		return acc * t;
	}
	double forceFromDrag(double d, double drag, double r, double v)
	{
		double area = 3.14159265 * pow(r,2);
		return 0.5 * d * drag * area * v * v;
	}
	double accelerationFromForce(double f, double m)
	{
		return f / m;
	}
	double computeLinearInterpolation(double v, double V0, double C0, double V1, double C1)
	{
		return C0 + ((v - V0) * (C1 - C0)) / (V1 - V0);
	}

};