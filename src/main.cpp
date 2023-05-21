#include "include/RayLib/raylib.h"
#include "include/RayLib/raymath.h"
#include "include/RayLib/rcamera.h"   
#include "include/GloVars.h"
#include "include/MineBorft/mineBorft.h"

#include <iostream>

Camera camera = { 0 };
int cameraMode = CAMERA_FIRST_PERSON;
Color background = {0, 137, 137, 255};

MineBorft mineborft;

bool initalize = false;

bool initMineBorft = false;
bool initPlane = false;

void Update()
{

    if(!initMineBorft && IsKeyPressed(KEY_ONE))
    {
        mineborft.InitMineBorft();
        initalize = true;
        initMineBorft = true;
    }


    if(initMineBorft)
    {
        mineborft.UpdateMineBorft();
    }

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

    //::cout << GetFPS() << std::endl;
}

void Draw()
{
    if(!initalize)
    {
        BeginDrawing();
        ClearBackground(background);
        EndDrawing();
    }
    if(initMineBorft)
    {
        mineborft.DrawMineBorft(background, camera);
    }
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

    while (!WindowShouldClose())
    {
        Update();
        Draw();
    }

    CloseWindow();
    

    return 0;
}