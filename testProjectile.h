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

		advance1_idle();
		advance2_fire();

		testReset();

	}
private:
	void constructor()
	{
		// setup
		Projectile p;
		// exercise

		// verify
		try
		{
			assert(p.getMass() == 0.0);
			assert(p.getRadius() == 0.0);
			assert(p.getFlightTime() == 0.0);
			assert(p.getFlightDistance() == 0.0);
			assert(p.getSpeed() == 0.0);

		}
		catch (...)
		{
			cout << "projectile_constructor failed";
		}
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
		try
		{
			assert(p.getFlightTime() == 0.5);
			assert(p.getFlightDistance() == 0.0);
			assert(p.getSpeed() == 0.0);
		}
		catch (...)
		{
			cout << "projectile_advance1_idle failed";
		}
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
		p.advance();
		// verify
		try
		{
			assert(p.getFlightTime() == 1.0);
			assert(p.getFlightDistance() == 0.0);
			assert(p.getSpeed() == 0.0);
		}
		catch (...)
		{
			cout << "projectile_advance2_2 failed";
		}
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
		try
		{
			assert(p.getFlightTime() == 0.0);
			assert(p.getFlightDistance() == 0.0);
			assert(p.getSpeed() == 0.0);
		}
		catch (...)
		{
			cout << "projectile_testReset failed";
		}
		// teardown
	}
};