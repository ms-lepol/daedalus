#include "dungeon.hpp"
#include <cstdlib>
#include <stdio.h>
#include <iostream>

namespace daedalus {

    void RogueDungeon::generate_random_dungeon(DungeonGenerationMethod method){

        switch (method) {
            case DungeonGenerationMethod::NAIVE :
                // Implement the naive dungeon generation algorithm here
                // Example: Just fill the dungeon with random rooms and corridors
                
                // Your naive dungeon generation logic
                break;
            case DungeonGenerationMethod::BSP:
            case DungeonGenerationMethod::DRUNKEN_WALK:
            case DungeonGenerationMethod::CELLULAR_AUTOMATA:
            case DungeonGenerationMethod::VORONOI:
            case DungeonGenerationMethod::PERLIN_NOISE:
                std::cerr << "Method not implemented yet" << std::endl;
                break;
            default:
                std::cerr << "Method not available for this kind of dungeon" << std::endl;
            }
    }



}