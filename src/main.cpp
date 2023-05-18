#include "include/RayLib/raylib.h"
#include "include/GloVars.h"

#include <iostream>

int main(void)
{
    InitWindow(SCREENWIDTH, SCREENHEIGHT - 5, "GameTesting");
    SetTargetFPS(INT32_MAX);

    Color background = {0, 137, 137, 255};

    int y = 0;
    int x = 0;

    while (!WindowShouldClose())
    {

        BeginDrawing();

        std::cout << GetFPS() << std::endl;

        if(y < SCREENHEIGHT)
        {
            for (int x = 0; x < SCREENWIDTH; x++)
            {
                auto r = double(x) / (SCREENWIDTH-1);
                auto g = double(y) / (SCREENHEIGHT-1);
                auto b = 0.25;

                u_char ir = 255.999 * r;
                u_char ig = 255.999 * g;
                u_char ib = 255.999 * b;
                DrawPixel(x,y, Color{ir, ig, ib, 255});
            }
            y++;
        }

        EndDrawing();
    }

    CloseWindow();
    

    return 0;
}