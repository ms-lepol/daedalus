#include "array_2D.hpp"
#include <cstddef>
#include <cstdint>
#include <tuple>
#include <vector>
#include <random>
#include <chrono>

/**
 * @file dungeon.hpp
 * @brief This file contains the definition of the Dungeon and RogueDungeon classes, 
 *        as well as enumerations for dungeon tiles and generation methods.
 */

namespace daedalus {

    /**
     * @enum DungeonTile
     * @brief Enumeration for different types of tiles in the dungeon.
     */
    enum class DungeonTile : std::uint8_t {
        WALL = 0,      /**< Represents a wall tile */
        FLOOR = 1,     /**< Represents a floor tile */
        ENTRANCE = 2,  /**< Represents the entrance tile */
        EXIT = 3       /**< Represents the exit tile */
    };

    /**
     * @enum DungeonGenerationMethod
     * @brief Enumeration for different methods of dungeon generation.
     */
    enum class DungeonGenerationMethod {
        NAIVE = 0,             /**< Naive generation method */
        BSP = 1,               /**< Binary Space Partitioning method */
        DRUNKEN_WALK = 2,      /**< Drunken Walk method */
        CELLULAR_AUTOMATA = 3, /**< Cellular Automata method */
        VORONOI = 4,           /**< Voronoi diagram method */
        PERLIN_NOISE = 5       /**< Perlin Noise method */
    };

    /**
     * @class Dungeon
     * @brief Base class representing a dungeon.
     */
    class Dungeon {
        private:
            Array_2D<std::uint8_t> tiles_; /**< 2D array representing the dungeon tiles */
            std::tuple<std::size_t, std::size_t> entrance_pos_; /**< Position of the entrance tile */
            std::tuple<std::size_t, std::size_t> exit_pos_; /**< Position of the exit tile */
            unsigned long seed_; /**< Seed for random generation */
            std::mt19937 rng_; /**< Random number generator */
        
        public:
            /**
             * @brief Constructor to initialize the dungeon with given rows and columns.
             * @param rows Number of rows in the dungeon.
             * @param cols Number of columns in the dungeon.
             */
            Dungeon(std::size_t rows, std::size_t cols,unsigned long seed = std::chrono::system_clock::now().time_since_epoch().count()) : 
            tiles_(rows, cols), 
            seed_(seed),
            rng_(seed) {
            };

            /**
             * @brief Overloaded operator to access a tile at a given position.
             * @param i Row index.
             * @param j Column index.
             * @return Reference to the tile at the given position.
             */
            const std::uint8_t& operator()(std::size_t i, std::size_t j) const;

            /**
             * @brief Get the number of rows in the dungeon.
             * @return Number of rows.
             */
            std::size_t rows() const;

            /**
             * @brief Get the number of columns in the dungeon.
             * @return Number of columns.
             */
            std::size_t cols() const;

            /**
             * @brief Set a tile at a given position.
             * @param i Row index.
             * @param j Column index.
             * @param tile Tile value to set.
             */
            void set_tile(std::size_t i, std::size_t j, std::uint8_t tile);

            /**
             * @brief Export dungeon data to a vector.
             * @param v Vector to store the dungeon data.
             */
            virtual void export_data(std::vector<std::uint8_t>& v) const;

            /**
             * @brief Check if a tile at a given position is a wall.
             * @param i Row index.
             * @param j Column index.
             * @return True if the tile is a wall, false otherwise.
             */
            bool is_wall(std::size_t i, std::size_t j) const;

            /**
             * @brief Check if a tile at a given position is the exit.
             * @param i Row index.
             * @param j Column index.
             * @return True if the tile is the exit, false otherwise.
             */
            bool is_exit(std::size_t i, std::size_t j) const;

            /**
             * @brief Generate a random dungeon using a specified method.
             * @param seed Seed for random generation.
             * @param method Method to use for dungeon generation.
             */
            virtual void generate_random_dungeon(DungeonGenerationMethod method);

            /**
             * @brief Set the entrance tile position.
             * @param i Row index.
             * @param j Column index.
             */
            void set_entrance(std::size_t i, std::size_t j);

            /**
             * @brief Set the exit tile position.
             * @param i Row index.
             * @param j Column index.
             */
            void set_exit(std::size_t i, std::size_t j);

            /**
             * @brief Find a path using Dijkstra's algorithm.
             * @return True if a path is found, false otherwise.
             */
            bool find_path_djikstra();

            /**
             * @brief Get the hot path found by Dijkstra's algorithm.
             * @return Vector of positions representing the hot path.
             */
            std::vector<std::tuple<std::size_t, std::size_t>> get_hot_path_djikstra() const;
    };

    /**
     * @class RogueDungeon
     * @brief Derived class representing a rogue-like dungeon.
     */
    class RogueDungeon : public Dungeon {
        public:
            /**
             * @brief Constructor to initialize the rogue dungeon with given rows and columns.
             * @param rows Number of rows in the dungeon.
             * @param cols Number of columns in the dungeon.
             */
            RogueDungeon(std::size_t rows, std::size_t cols);

            /**
             * @brief Place a room in the dungeon.
             * @param from Starting position of the room.
             * @param to Ending position of the room.
             * @return True if the room is placed successfully, false otherwise.
             */
            bool place_room(std::tuple<std::size_t> from, std::tuple<std::size_t> to);

            /**
             * @brief Generate a random dungeon using a specified method.
             * @param seed Seed for random generation.
             * @param method Method to use for dungeon generation.
             */
            void generate_random_dungeon(DungeonGenerationMethod method) override;

            /**
             * @brief Perform a step of naive dungeon generation.
             */
            void generate_random_dungeon_naive_step();

            /**
             * @brief Perform a step of BSP dungeon generation.
             */
            void generate_random_dungeon_bsp_step();

            /**
             * @brief Perform a step of drunken walk dungeon generation.
             */
            void generate_random_dungeon_drunken_walk_step();

            /**
             * @brief Perform a step of cellular automata dungeon generation.
             */
            void generate_random_dungeon_cellular_automata_step();
    };
}