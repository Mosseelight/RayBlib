#ifndef MINEBORFT_H
#define MINEBORFT_H

#include "MeshGen.h"
#include "../RayLib/raylib.h"
#include "../RayLib/raymath.h"
#include "../RayLib/rcamera.h"   

class MineBorft
{
public:
    Chunk *chunks;
    int chunkCount = 5;

    void InitMineBorft()
    {
        chunks = new Chunk[chunkCount];

        for (int i = 0; i < chunkCount; i++)
        {
            //chunk size wont change it will always be 16
            chunks[i] = Chunk(16, 16, 16, Vector3{static_cast<float>(i * 16), 0, 0});
            chunks[i].AssignPositions();
            chunks[i].ApplyCKArrCulling();
            if(i == 0)
                chunks[i].ApplyWCKArrCulling(chunks, chunkCount);
        }
    }
    void UpdateMineBorft()
    {
        
    }
    void DrawMineBorft(Color background, Camera camera)
    {
        BeginDrawing();
        ClearBackground(background);

            BeginMode3D(camera);

            for (int c = 0; c < chunkCount; c++)
            {
                for (int i = 0; i < chunks[c].cPosSize; i++)
                {
                    //needed if statement to check if there is a block position that is zero
                    //which means it has not been included in the cCDpos except for the first
                    //position which is always 0
                    if(!Vector3Equals(chunks[c].cCDPositions[i], Vector3Zero()) || i == 0)
                        DrawCube(chunks[c].cCDPositions[i], 1, 1, 1, Color{static_cast<u_char>(i), 0, 0, 255});
                }
            }
            
            EndMode3D();

        EndDrawing();
    }

};

//2 fps wiht 5 chunk full render
//40 fps with 5 chunk with cube culling
//45 fps with 5 chunk smaller array of cube culling

#endif