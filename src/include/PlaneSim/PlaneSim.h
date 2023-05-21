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

    float simSpeed = 0.0001f;

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
        /*plane.position = Vector3Scale(Vector3Add(plane.position, planephySim.PlaneMovDir(
            plane.up, plane.backward, plane.forward, plane.down,
            plane.dragCoef, plane.liftCoef, plane.thrust, plane.mass,
            plane.speed, plane.wingSpan, plane.wingWidth
        )), simSpeed * deltaTime);*/
        //plane.position = Vector3Scale(Vector3Add(planephySim.CalThrustDir(Vector3{0,0,1}, 1), plane.position), simSpeed * deltaTime);
        plane.velocity = planephySim.AddRelForce(planephySim.CalThrustDir(plane.forward, plane.thrust), Vector3{-45*RAD2DEG,0,0});
        plane.position = Vector3Add(plane.position, Vector3Scale(plane.velocity, simSpeed));
        //plane.velocity = planephySim.AddRelForce(planephySim.CalDownDir(plane.down, plane.mass), Vector3{0,0,0});
        //plane.position = Vector3Add(plane.position, Vector3Scale(plane.velocity, simSpeed));
        plane.velocity = planephySim.AddRelForce(planephySim.CalDragDir(plane.backward, plane.dragCoef, plane.speed), Vector3{45*RAD2DEG,0,0});
        plane.position = Vector3Add(plane.position, Vector3Scale(plane.velocity, simSpeed));
        //plane.velocity = planephySim.AddRelForce(planephySim.CalLiftDir(plane.up, plane.liftCoef, plane.speed, plane.wingSpan, plane.wingWidth), Vector3{-45*RAD2DEG,0,0});
        //plane.position = Vector3Add(plane.position, Vector3Scale(plane.velocity, simSpeed));
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