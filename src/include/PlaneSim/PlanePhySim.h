#ifndef PLANEPHYSIM_H
#define PLANEPHYSIM_H

#include "../RayLib/raylib.h"
#include "../RayLib/raymath.h"

class PlanePhySim
{
public:

    //all forces should be multipled by the direction they go
    //eg. drag would go opposite of the forward of the plane and lift would go from a cross up of the wings
    double CalDragF(double dragC, Vector3 velocity) // This would be reverse of the direction of the plane
    {
        double speed = Vector3LengthSqr(velocity);
        return 0.5 * airDesnity * dragC * speed * speed;
    }

    double CalLiftF(double liftC, Vector3 velocity, double wingSpan, double wingWidth)
    {
        //technically this means the wings are square
        double wingArea = wingSpan * wingWidth;
        double speed = Vector3LengthSqr(velocity);
        return 0.5 * airDesnity * speed * wingArea * liftC;
    }

    double CalDownF(double mass)
    {
        return mass * gravity;
    }

    //forward vector that moves the plane forward
    Vector3 CalThrustDir()
    {
        
    }

    Vector3 CalDragDir()
    {

    }

private:

    double gravity = 9.80665; // Gravity speed in m/s
    double airDesnity = 1.225; // Air Density

};

#endif