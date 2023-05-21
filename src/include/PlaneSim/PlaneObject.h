#ifndef PLANEOBJECT_H
#define PLANEOBJECT_H

#include "../RayLib/raylib.h"
#include "../RayLib/raymath.h"
#include <iostream>

class PlaneObject
{
public:
    double mass; // Mass of the plane
    double wingSpan; // Wingspan of the plane
    double wingWidth; // Wing Width of the plane
    double length; // Length of the plane
    double dragCoef; // Drag Coefficent of the plane
    double liftCoef; // Life Coefficent of the plane
    double thrust; // Thrust of the plane

    Vector3 position; // Position of the plane
    Vector3 velocity; // Velocity of the plane
    Vector3 rotation; // Rotation of the plane (In Radians)
    double speed = 0;

    Vector3 forward;
    Vector3 backward;
    Vector3 up;
    Vector3 down;

    PlaneObject()
    {

    }

    PlaneObject(double _mass, double _wingspan, double _wingWidth, double _length, double _dragCoef, double _liftCoef, double _thrust, Vector3 _position, Vector3 _velocity, Vector3 _rotation)
    {
        mass = _mass;
        wingSpan = _wingspan;
        wingWidth = _wingWidth;
        length = _length;
        dragCoef = _dragCoef;
        liftCoef = _liftCoef;
        thrust = _thrust;
        position = _position;
        velocity = _velocity;
        rotation = _rotation;
    }

    void CalculateForward()
    {
        forward = Vector3{0,0,1};
    }

    void CalculateBackward()
    {
        backward = Vector3{0,0,-1};
    }

    void CalculateUp()
    {
        up = Vector3{0,1,0};
    }

    void CalculateDown()
    {
        down = Vector3{0,-1,0};
    }

    void calSpeed(Vector3 prevPos, Vector3 curPos, double deltaTime)
    {
        speed = Vector3Length(Vector3Subtract(prevPos, curPos)) / deltaTime;
    }

    void CalVelocity(Vector3 prevPos, Vector3 curPos, double deltaTime)
    {
        velocity = Vector3Subtract(prevPos, curPos);
    }

};

#endif