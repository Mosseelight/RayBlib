#ifndef PLANESIM_H
#define PLANESIM_H

#include "../RayLib/raylib.h"
#include "../RayLib/raymath.h"
#include "../RayLib/rcamera.h"   
#include "PlaneObject.h"
#include "PlanePhySim.h"
#include <iostream>

class PlaneSim
{
public:
    void InitPlaneSim()
    {
        plane = new PlaneObject(100, 40, 5, 20, 0.25, 0.5, 100, Vector3{0,0,0}, Vector3{0,0,0}, Vector3{0,0,0});
        plane->CalculateForward();
        plane->CalculateBackward();
        plane->CalculateUp();
        plane->CalculateDown();
    }

    void UpdatePlaneSim(double deltaTime)
    {
        plane->CalculateForward();
        plane->CalculateBackward();
        plane->CalculateUp();
        plane->CalculateDown();

        Vector3 prevPlanePos = plane->position;

        //plane cal
        /*plane->position = Vector3Scale(Vector3Multiply(plane->position, planephySim.PlaneMovDir(
            plane->up, plane->backward, plane->forward, plane->down,
            plane->dragCoef, plane->liftCoef, plane->thrust, plane->mass,
            plane->speed, plane->wingSpan, plane->wingWidth
        )), deltaTime);*/
        plane->position = Vector3Subtract(Vector3{0,0.1f,0}, plane->position);
        std::cout << plane->position.y << std::endl;

        plane->calSpeed(prevPlanePos, plane->position, deltaTime);

    }

    void DrawPlaneSim(Color background, Camera camera)
    {   
        BeginDrawing();
        ClearBackground(background);

            BeginMode3D(camera);

                DrawCube(plane->position, 1, 1, 1, RAYWHITE);
            
            EndMode3D();

        EndDrawing();
    }
private:
    PlaneObject *plane;
    PlanePhySim planephySim;
};



#endif