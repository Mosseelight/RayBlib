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
    Vector3 rotation; // Rotation of the plane

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

    //calculates vector at correct angle from 0,0,0
    //then adds on the positon of the plane to get
    //the correct forward direction
    void CalculateForward()
    {
        Matrix rotMatrx = MatrixRotate(Vector3{0,0,1}, rotation.y);
        forward = Vector3Transform(Vector3{1,1,1}, rotMatrx);
        forward = Vector3Add(forward, position);
    }

    void CalculateBackward(double yRot)
    {
        Matrix rotMatrx = MatrixRotate(Vector3{0,0,-1}, yRot);
        backward = Vector3Transform(Vector3{1,1,1}, rotMatrx);
        backward = Vector3Add(backward, position);
        std::cout << backward.x << " " << backward.y << " " << backward.z << std::endl;
    }

};

#endif