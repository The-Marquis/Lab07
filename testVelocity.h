#pragma once
/***********************************************************************
 * Header File:
 *    Test Velocity : Test the Velocity class
 * Author:
 *    Br. Helfrich
 * Summary:
 *    All the unit tests for the Velocity class
 ************************************************************************/


#pragma once

#include "velocity.h"
#include <cassert>
#include <vector>


using namespace std;

/*******************************
 * TEST Velocity
 * A friend class for Velocity which contains the Velocity unit tests
 ********************************/
class TestVelocity
{
public:
    void run()
    {
        constructor();

        setDX();
        setDXDY();

        setDY();

        addDX();
        addDY();
        addDX2();
        addDY2();

        getSpeed();
        getSpeed2();
        reverse();
        reverse2();
    }

private:

    bool closeEnough(double value, double test, double tolerance)const
    {
        double difference = value - test;
        return (difference >= -tolerance) && (difference <= tolerance);
    }

    // Test the default constructor
    void constructor()
    {  // setup
        Velocity v;
        // exercise
        double dx = v.getDX();
        double dy = v.getDY();

        // verify
        assert(dx == 0);
        assert(dy == 0);
        // teardown

    }


    void setDX()
    {  // setup
        Velocity v;
        // exercise
        v.setDX(5.4);

        // verify
        assert(v.dx == 5.4);
        
        // teardown

    }
    void setDY()
    {  // setup
        Velocity v;
        // exercise
        
        v.setDY(8.3);

        // verify
        assert(v.dy == 8.3);
        
        // teardown

    }
    void setDXDY()
    {
        // setup
        Velocity v;
        // exercise

        v.setDxDy(8.3, 5.4);

        // verify
        assert(v.dx == 8.3);
        assert(v.dy == 5.4);

        // teardown
    }

    void getSpeed2()
    {
        // setup
        Velocity v;
        // exercise

        v.setDX(3.0);
        v.setDY(4.0);

        double speed = v.getSpeed();
        // verify
        assert(closeEnough(speed, 5.00, 0.0001));
      

        // teardown
    }
    void getSpeed()
    {
        // setup
        Velocity v;
        // exercise

        v.setDX(1.0);
        v.setDY(0.0);

        double speed = v.getSpeed();

        // verify
        assert(closeEnough(speed, 1.00, 0.0001));


        // teardown
    }
    void addDX()
    {  // setup
        Velocity v;
        // exercise

        v.setDX(8.3);
        v.addDX(2.0);

        // verify
        assert(v.dx == 8.3 + 2.0);

        // teardown

    }
    void addDX2()
    {  // setup
        Velocity v;
        // exercise

        v.setDX(-0.1);
        v.addDX(-1.9);

        // verify
        assert(v.dx == -0.1 + -1.9);

        // teardown

    }
    void addDY()
    {  // setup
        Velocity v;
        // exercise

        v.setDY(8.3);
        v.addDY(2.0);

        // verify
        assert(v.dy == 8.3 + 2.0);

        // teardown

    }
    void addDY2()
    {  // setup
        Velocity v;
        // exercise

        v.setDY(-7.2);
        v.addDY(-2.8);

        // verify
        assert(v.dy == -2.8 + -7.2);

        // teardown

    }
    void reverse()
    {  // setup
        Velocity v;
        // exercise

        v.setDY(8.3);
        v.setDX(2.0);
        v.reverse();
        // verify
        assert(v.dy == -8.3);
        assert(v.dx == -2.0);
        // teardown

    }
    void reverse2()
    {  // setup
        Velocity v;
        // exercise

        v.setDY(-8.3);
        v.setDX(-2.0);
        v.reverse();
        // verify
        assert(v.dy == 8.3);
        assert(v.dx == 2.0);
        // teardown

    }
};