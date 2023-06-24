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
		assert(p.getFlightTime() == 0.0);
		assert(p.getFlightDistance() == 0.0);
		assert(p.getSpeed() == 0.0);
		// teardown

	}

	

	void advance1_idle()
	{
		// advance when not fired
		// setup
		Projectile p;
		// exercise
		p.advance();
		// verify
		assert(p.getFlightTime() == 0.0);
		assert(p.getFlightDistance() == 0.0);
		assert(p.getSpeed() == 0.0);
		// teardown

	}

	void advance2_fire()
	{
		// advance when fired once
		// setup
		Projectile p;
		// exercise
		p.advance();
		p.fire();
		// verify
		assert(p.getFlightTime() == 0.0);
		assert(p.getFlightDistance() == 0.0);
		assert(p.getSpeed() == 0.0);
		// teardown

	}


	void testReset()
	{
		// advance, fire once, advance, and reset
		// setup
		Projectile p;
		// exercise
		p.advance();
		p.fire();
		p.advance();
		p.reset();
		// verify
		assert(p.getFlightTime() == 0.0);
		assert(p.getFlightDistance() == 0.0);
		assert(p.getSpeed() == 0.0);
		// teardown
	}
};