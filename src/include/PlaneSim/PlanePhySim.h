#ifndef PLANEPHYSIM_H
#define PLANEPHYSIM_H

#include "../RayLib/raylib.h"
#include "../RayLib/raymath.h"
#include <cmath>

class PlanePhySim
{
public:

    PlanePhySim()
    {

    }

    Vector3 CalLiftDir(Vector3 velocity, Vector3 right, double liftC, double speed, float AOA)
    {
        Vector3 liftV = Vector3Subtract(velocity, Vector3Scale(right, Vector3DotProduct(velocity, right)));
        float liftVsqr = Vector3LengthSqr(liftV);

        liftC = sin(AOA * DEG2RAD);
        return Vector3Scale(Vector3CrossProduct(Vector3Normalize(liftV), right), liftVsqr * liftC);
    }

    Vector3 CalThrustDir(Vector3 forward, double thrustAmount)
    {
        return Vector3Scale(forward, thrustAmount);
    }

    /*Vector3 CalDragDir(Vector3 backward, double dragC, double speed)
    {
        return Vector3Scale(backward, CalDragF(dragC, speed));
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
    }*/

    Vector3 AddRelForce(Vector3 force, Vector3 objRot)
    {
        Matrix rotMat = MatrixRotateXYZ(objRot); 
        return Vector3Transform(force, rotMat);
    }

private:

    double gravity = 9.80665; // Gravity speed in m/s
    double airDesnity = 1.225; // Air Density
};

#endif