#ifndef PLANEPHYSIM_H
#define PLANEPHYSIM_H

#include "../RayLib/raylib.h"
#include "../RayLib/raymath.h"

class PlanePhySim
{
public:

    PlanePhySim()
    {

    }

    Vector3 CalLiftDir(Vector3 up, double liftC, double speed, double wingSpan, double wingWidth)
    {
        return Vector3Scale(up, CalLiftF(liftC, speed, wingSpan, wingWidth));
    }

    Vector3 CalDragDir(Vector3 backward, double dragC, double speed)
    {
        return Vector3Scale(backward, CalDragF(dragC, speed));
    }

    Vector3 CalThrustDir(Vector3 forward, double thrustAmount)
    {
        return Vector3Scale(forward, thrustAmount);
    }

    Vector3 CalDownDir(Vector3 down, double mass)
    {
        return Vector3Scale(down, CalDownF(mass));
    }

    Vector3 PlaneMovDir(Vector3 up, Vector3 backward, Vector3 forward, Vector3 down, 
    double dragC, double liftC, double thrustAmount, double mass, double speed, double wingSpan, double wingWidth)
    {
        return Vector3Multiply(Vector3Multiply(CalLiftDir(up, liftC, speed, wingSpan, wingWidth), CalDragDir(backward, dragC, speed)), 
        Vector3Multiply(CalThrustDir(forward, thrustAmount), CalDownDir(down, mass)));
    }

    Vector3 AddRelForce(Vector3 force, Vector3 objRot)
    {
        Matrix rotMat = MatrixRotateXYZ(objRot); 
        return Vector3Transform(force, rotMat);
    }

private:

    double gravity = 9.80665; // Gravity speed in m/s
    double airDesnity = 1.225; // Air Density

    //all forces should be multipled by the direction they go
    //eg. drag would go opposite of the forward of the plane and lift would go from a cross up of the wings
    double CalDragF(double dragC, double speed) // This would be reverse of the direction of the plane
    {
        return 0.5 * dragC * speed;
    }

    double CalDownF(double mass)
    {
        return mass * gravity;
    }

    //Lift c should change based on AOA
    //create a function that returns 0 to 1 based on AOA as input
    double CalLiftF(double liftC, double speed, double wingSpan, double wingWidth)
    {
        //technically this means the wings are square
        double wingArea = wingSpan * wingWidth;
        return 0.5 * airDesnity * speed * wingArea * liftC;
    }

};

#endif