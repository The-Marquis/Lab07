#pragma once
#include "projectile.h"
#include <cassert>
#include <vector>

class testProjectile
{
public:
	void run()
	{
		constructor();

		setMass();
		setMass2();

		setRadius();
		setRadius2();
	}
private:
	void constructor()
	{
		// setup
		Projectile p;
		// exercise

		// verify
		assert(p.getMass() == 0.0);
		assert(p.getRadius() == 0.0);
		// teardown

	}

	void setMass()
	{
		// setup
		Projectile p;
		// exercise
		p.setMass(10.0);

		// verify
		assert(p.getMass() == 10.0);
		// teardown

	}

	void setMass2()
	{
		// setup
		Projectile p;
		// exercise
		p.setMass(-10.0);
		// verify
		assert(p.getMass() == 0.0);
		// teardown

	}

	void setRadius()
	{
		// setup
		Projectile p;
		// exercise
		p.setRadius(10.0);

		// verify
		assert(p.getRadius() == 10.0);
		// teardown

	}

	void setRadius2()
	{
		// setup
		Projectile p;
		// exercise
		p.setRadius(-10.0);
		// verify
		assert(p.getRadius() == 0.0);
		// teardown

	}
};