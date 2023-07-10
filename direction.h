#pragma once
class Direction
{
public:
	Direction() {};
	double getAngle()
	{
		return angle;
	}
	void setAngle(double newAngle)
	{
		this->angle = newAngle;
	}
private:
	double angle;
};