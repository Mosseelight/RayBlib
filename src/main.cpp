#include "include/RayLib/raylib.h"
#include "include/GloVars.h"

#include <iostream>

int main(void)
{
    InitWindow(SCREENWIDTH, SCREENHEIGHT, "GameTesting");
    SetTargetFPS(INT32_MAX);

    while (!WindowShouldClose)
    {
        BeginDrawing();

            ClearBackground(RAYWHITE);

        EndDrawing();
    }

    CloseWindow();
    

    return 0;
}