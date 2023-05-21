#ifndef MESHGEN_H
#define MESHGEN_H

#include "../RayLib/raylib.h"
#include "../RayLib/raymath.h"
#include <iostream>
#include <vector>

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
    std::vector<Vector3> nPositions; //neightbour positions from other chunks plus the chunks own blocks
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

    void ApplyCKArrCulling()
    {
        for (int i = 0; i < cXTot * cYTot * cZTot; i++)
        {
            if(!CheckCubeCullCK(cPositions[i], cPositions, cPosSize))
            {
                cCDPositions[i] = cPositions[i];
                cCDPosSize++;
            }
        }
    }

    //Should get only the edges of "opposite sides" of the neighbouring chunks instead of the whole thing
    void ApplyWCKArrCulling(Chunk chks[], int ChunkAmount) 
    {
        std::vector<Chunk> chunks;
        for (int c = 0; c < ChunkAmount; c++)
        {
            if(Vector3Equals(chks[c].position, Vector3{position.x + 16, position.y, position.z})) // +1 on the x check
                chunks.push_back(chks[c]); std::cout << chks[c].position.x << chks[c].position.y << chks[c].position.z << std::endl;
            if(Vector3Equals(chks[c].position, Vector3{position.x - 16, position.y, position.z})) // -1 on the x check
                chunks.push_back(chks[c]);
            if(Vector3Equals(chks[c].position, Vector3{position.x, position.y + 16, position.z})) // +1 on the y check
                chunks.push_back(chks[c]);
            if(Vector3Equals(chks[c].position, Vector3{position.x, position.y - 16, position.z})) // -1 on the y check
                chunks.push_back(chks[c]);
            if(Vector3Equals(chks[c].position, Vector3{position.x, position.y, position.z + 16})) // +1 on the z check
                chunks.push_back(chks[c]);
            if(Vector3Equals(chks[c].position, Vector3{position.x, position.y, position.z - 16})) // -1 on the z check
                chunks.push_back(chks[c]);
        }
    }

private:

    bool CheckCubeCullCK(Vector3 cPos, Vector3 csPos[], int csPosSize)
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

//come back to
/*class World
{
public:
    std::vector<Chunk> chunks;
    std::vector<Vector3> blocks;
    std::vector<Vector3> cDBlocks;

    World()
    {

    }

    World(int chunkAmount)
    {
        for (int i = 0; i < chunkAmount; i++)
        {
            Chunk _chunk(16, 16, 16, Vector3{static_cast<float>(i * 16), 0, 0});
            chunks.push_back(_chunk);
            chunks[i].AssignPositions();
            for (int p = 0; p < chunks[i].cPosSize; p++)
            {
                blocks.push_back(chunks[i].cPositions[p]);
            }
        }

        for (int b = 0; b < blocks.size(); b++)
        {
            if(!CheckCubeCull(blocks[b], blocks, blocks.size()))
            {
                cDBlocks.push_back(blocks[b]);
            }
        }
        
    }

private:

    bool CheckCubeCull(Vector3 cPos, std::vector<Vector3> csPos, int csPosSize)
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
};*/

#endif