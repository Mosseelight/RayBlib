#ifndef RAYLIBNOTINCLUDINGIMPORTANTSHIT_H
#define RAYLIBNOTINCLUDINGIMPORTANTSHIT_H

#include "RayLib/raylib.h"

Vector3 MultiplyFloatVector3(float value, Vector3 vector)
{
    return {vector.x * value, vector.y * value, vector.z * value};
}

Vector3 DivideFloatVector3(float value, Vector3 vector)
{
    return {vector.x / value, vector.y / value, vector.z / value};
}

Vector3 AddFloatVector3(float value, Vector3 vector)
{
    return {vector.x + value, vector.y + value, vector.z + value};
}

Vector3 SubtractFloatVector3(float value, Vector3 vector)
{
    return {vector.x - value, vector.y - value, vector.z - value};
}

Vector2 MultiplyFloatVector2(float value, Vector2 vector)
{
    return {vector.x * value, vector.y * value};
}

Vector2 DivideFloatVector2(float value, Vector2 vector)
{
    return {vector.x / value, vector.y / value};
}

Vector2 AddFloatVector2(float value, Vector2 vector)
{
    return {vector.x + value, vector.y + value};
}

Vector2 SubtractFloatVector2(float value, Vector2 vector)
{
    return {vector.x - value, vector.y - value};
}

#endif