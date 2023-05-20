#include "include/RayLib/raylib.h"
#include "include/RayLib/raymath.h"
#include "include/RayLib/rcamera.h"   
#include "include/GloVars.h"
#include "include/MeshGen.h"

#include <iostream>

Camera camera = { 0 };
int cameraMode = CAMERA_FIRST_PERSON;
Color background = {0, 137, 137, 255};
//World *world;
Chunk *chunks;
int chunkCount = 5;

void Update()
{
    UpdateCameraPro(&camera,
            (Vector3){
                (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))*0.1f -      
                (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))*0.1f,    
                (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))*0.1f -   
                (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))*0.1f,
                (IsKeyDown(KEY_SPACE))*0.1f -      
                (IsKeyDown(KEY_LEFT_SHIFT))*0.1f                                               
            },
            (Vector3){
                GetMouseDelta().x*0.05f,                            
                GetMouseDelta().y*0.05f,                            
                0.0f                                               
            },
            0.0f); 

    //2 fps wiht 5 chunk full render
    //40 fps with 5 chunk with cube culling
    //45 fps with 5 chunk smaller array of cube culling
    std::cout << GetFPS() << std::endl;
}

void Draw()
{
    BeginDrawing();
    ClearBackground(background);

        BeginMode3D(camera);

        for (int c = 0; c < chunkCount; c++)
        {
            for (int i = 0; i < chunks[c].; i++)
            {
                //needed if statement to check if there is a block position that is zero
                //which means it has not been included in the cCDpos except for the first
                //position which is always 0
                if(!Vector3Equals(chunks[c].cCDWPositions[i], Vector3Zero()) || i == 0)
                    DrawCube(chunks[c].cCDWPositions[i], 1, 1, 1, Color{static_cast<u_char>(i), 0, 0, 255});
            }
        }
        
        EndMode3D();

    EndDrawing();
}

int main(void)
{
    InitWindow(SCREENWIDTH, SCREENHEIGHT, "GameTesting");
    //if refresh rate 60 then fps should be 120 or less
    //if refresh rate 300 then fps should be 300 or less

    DisableCursor();
    SetTargetFPS(300);

    camera.position = (Vector3){ 0.0f, 2.0f, 4.0f };
    camera.target = (Vector3){ 0.0f, 2.0f, 0.0f };      
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };         
    camera.fovy = 60.0f;                                
    camera.projection = CAMERA_PERSPECTIVE;    

    //world = new World(1);

    chunks = new Chunk[chunkCount];

    for (int i = 0; i < chunkCount; i++)
    {
        chunks[i] = Chunk(16, 16, 16, Vector3{static_cast<float>(i * 16), 0, 0});
        chunks[i].AssignPositions();
        chunks[i].ApplyWArrCulling();
    }

    while (!WindowShouldClose())
    {
        Update();
        Draw();
    }

    CloseWindow();
    

    return 0;
}