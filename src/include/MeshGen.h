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
    int cPosSize = 0;
    int cCDPosSize = 0;
    Vector3 *cPositions; //original chunk with all positions avaliable
    Vector3 *cCDPositions; //generated culling that only has positions that have a "air" block next
    Vector3 position;

    Chunk()
    {
        
    }

    Chunk(int _cXTot, int _cYTot, int _cZTot, Vector3 pos)
    {
        cXTot = _cXTot;
        cYTot = _cYTot;
        cZTot = _cZTot;
        position = pos;
        cPositions = new Vector3[_cXTot * _cXTot * _cZTot];
        cCDPositions = new Vector3[_cXTot * _cXTot * _cZTot];
        cPosSize = cXTot * cYTot * cZTot;
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

    void ApplyArrCulling()
    {
        for (int i = 0; i < cXTot * cYTot * cZTot; i++)
        {
            if(!CheckCubeCull(cPositions[i], cPositions, cPosSize))
            {
                cCDPositions[i] = cPositions[i];
                cCDPosSize++;
            }
        }
    }

private:

    bool CheckCubeCull(Vector3 cPos, Vector3 csPos[], int csPosSize)
    {
        int checks = 0; //if this is 6 then there is 6 cubes surrounding the cube
        for (int i = 0; i < csPosSize; i++)
        {
            if(Vector3Equals(csPos[i], Vector3{cPos.x + 1, cPos.y, cPos.z})) // +1 on the x check
                checks++;
            if(Vector3Equals(csPos[i], Vector3{cPos.x - 1, cPos.y, cPos.z})) // -1 on the x check
                checks++;
            if(Vector3Equals(csPos[i], Vector3{cPos.x, cPos.y + 1, cPos.z})) // +1 on the y check
                checks++;
            if(Vector3Equals(csPos[i], Vector3{cPos.x, cPos.y - 1, cPos.z})) // -1 on the y check
                checks++;
            if(Vector3Equals(csPos[i], Vector3{cPos.x, cPos.y, cPos.z + 1})) // +1 on the z check
                checks++;
            if(Vector3Equals(csPos[i], Vector3{cPos.x, cPos.y, cPos.z - 1})) // -1 on the z check
                checks++;
        }
        if(checks == 6)
            return true;
        
        return false;
    }

};

#endif