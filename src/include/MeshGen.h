#ifndef MESHGEN_H
#define MESHGEN_H

#include "RayLib/raylib.h"
#include <iostream>

class Chunk
{
public:
    int cXTot = 16;
    int cYTot = 16;
    int cZTot = 16;
    Vector3 *cPositions;
    Vector3 position;

    Chunk(int _cXTot, int _cYTot, int _cZTot, Vector3 pos)
    {
        cXTot = _cXTot;
        cYTot = _cYTot;
        cZTot = _cZTot;
        position = pos;
        cPositions = new Vector3[_cXTot * _cXTot * _cZTot];
    }

    void AssignPositions()
    {
        uint index = 0;
        for (int z = 0; z < cZTot; z++)
        {
            for (int y = 0; y < cYTot; y++)
            {
                for (int x = 0; x < cXTot; x++)
                {
                    cPositions[index] = Vector3Add(Vector3{static_cast<float>(x), static_cast<float>(y), static_cast<float>(z)}, position);
                    index++;
                }
                
            }
        }
        
    }

};

#endif