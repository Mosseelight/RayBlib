#ifndef RAY_H
#define RAY_H

#include "RayLib/raylib.h"
#include "RayLib/raymath.h"
#include "raylibnotincludingimportantshit.h"

class ray {
    public:
        ray() {}
        ray(Vector3& origin, Vector3& direction)
            : orig(origin), dir(direction)
        {}

        Vector3 origin() const  { return orig; }
        Vector3 direction() const { return dir; }

        Vector3 at(float t) const {
            return Vector3Add(orig, MultiplyFloatVector3(t, dir));
        }

    public:
        Vector3 orig;
        Vector3 dir;
};

#endif