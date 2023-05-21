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

    PlaneObject plane;
    PlanePhySim planephySim = PlanePhySim();
    Vector3 pos;

    float simSpeed = 0.01f;

    PlaneSim(PlaneObject _plane)
    {
        plane = _plane;
    }

    void InitPlaneSim()
    {
        plane.CalculateForward();
        plane.CalculateBackward();
        plane.CalculateUp();
        plane.CalculateDown();
    }

    void UpdatePlaneSim(double deltaTime)
    {
        Vector3 prevPlanePos = plane.position;

        //plane cal
        plane.velocity = planephySim.AddRelForce(planephySim.CalLiftDir(
            plane.velocity, Vector3{1,0,0}, plane.liftCoef, 
            plane.speed, 45
        ), Vector3{0, 0, 0});
        plane.position = Vector3Add(plane.position, Vector3Scale(plane.velocity, simSpeed));
        plane.velocity = planephySim.AddRelForce(planephySim.CalThrustDir(Vector3{0,0,1}, 3), Vector3{0, 0, 0});
        plane.position = Vector3Add(plane.position, Vector3Scale(plane.velocity, simSpeed));
        std::cout << plane.position.x << " Plane " << plane.position.y << " Plane " << plane.position.z << std::endl;

        plane.calSpeed(prevPlanePos, plane.position, simSpeed);
        std::cout << plane.speed << " speed" << std::endl;

    }

    void DrawPlaneSim(Color background, Camera camera)
    {   
        BeginDrawing();
        ClearBackground(background);

            BeginMode3D(camera);

                DrawCube(plane.position, 1, 1, 1, RAYWHITE);
            
            EndMode3D();

        EndDrawing();
    }
};



#endif