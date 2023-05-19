#include "include/RayLib/raylib.h"
#include "include/GloVars.h"

#include <iostream>

int main(void)
{
    InitWindow(SCREENWIDTH, SCREENHEIGHT, "GameTesting");
    //if refresh rate 60 then fps should be 120 or less
    //if refresh rate 300 then fps should be 300 or less
    SetTargetFPS(120);

    Color background = {0, 137, 137, 255};

    int y = 0;
    int x = 0;

    while (!WindowShouldClose())
    {

        BeginDrawing();

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