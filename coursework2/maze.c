/**
 * @file maze.c
 * @author MUHAMAD HEWA RAHIM
 * @brief Code for the maze game for COMP1921 Assignment 2
 * NOTE - You can remove or edit this file however you like - this is just a provided skeleton code
 * which may be useful to anyone who did not complete assignment 1.
 */

#include <stdio.h>
#include <stdlib.h>

// defines for max and min permitted dimensions
#define MAX_DIM 100
#define MIN_DIM 5

// defines for the required autograder exit codes
#define EXIT_SUCCESS 0
#define EXIT_ARG_ERROR 1
#define EXIT_FILE_ERROR 2
#define EXIT_MAZE_ERROR 3

typedef struct __Coord
{
    int x;
    int y;
} coord;

typedef struct __Maze
{
    char **map;
    int height;
    int width;
    coord start;
    coord end;
} maze;

/**
 * @brief Initialise a maze object - allocate memory and set attributes
 *
 * @param this pointer to the maze to be initialised
 * @param height height to allocate
 * @param width width to allocate
 * @return int 0 on success, 1 on fail
 */
int create_maze(maze *this, FILE *file, int height, int width)
{
    this->height = height;
    this->width = width;

}

/**
 * @brief Free the memory allocated to the maze struct
 *
 * @param this the pointer to the struct to free
 */
void free_maze(maze *this)
{
}

/**
 * @brief Validate and return the width of the mazefile
 *
 * @param file the file pointer to check
 * @return int 0 for error, or a valid width (5-100)
 */
int get_width(FILE *file)
{
    int maze_width = 0;
	int buffer_size = 100;
    char line_buffer[buffer_size];
    while (fgets(line_buffer, buffer_size, file) != '\n') {
        if (strlen(line_buffer) > maze_width && maze_width == 0) {
            maze_width = strlen(line_buffer);
        }
        if (strlen(line_buffer) > maze_width && maze_width != 0) {
            printf("Error: Invalid maze file.\n");
            return 0;
        }
        if (strlen(line_buffer) < MIN_DIM || strlen(line_buffer) > MAX_DIM) {
            printf("Error: Invalid maze file.\n");
            return 0;
        }
    }
    return maze_width;
}

/**
 * @brief Validate and return the height of the mazefile
 *
 * @param file the file pointer to check
 * @return int 0 for error, or a valid height (5-100)
 */
int get_height(FILE *file)
{
    int maze_height = 0;
	int buffer_size = 100;
    char line_buffer[buffer_size];
    while (fgets(line_buffer, buffer_size, file) != '\n') {
        maze_height++;
    }
    if (maze_height < MIN_DIM || maze_height > MAX_DIM) {
        printf("Error: Invalid maze file.\n");
        return 0;
    }
    return maze_height;
}

/**
 * @brief read in a maze file into a struct
 *
 * @param this Maze struct to be used
 * @param file Maze file pointer
 * @return int 0 on success, 1 on fail
 */
int read_maze(maze *this, FILE *file, char *filename)
{
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not find or open the file.\n");
        exit(EXIT_FILE_ERROR);
    }
    if (get_height(file) == 0 || get_width(file) == 0) {
        exit(EXIT_MAZE_ERROR);
    }
}

/**
 * @brief Prints the maze out - code provided to ensure correct formatting
 *
 * @param this pointer to maze to print
 * @param player the current player location
 */
void print_maze(maze *this, coord *player)
{
    // make sure we have a leading newline..
    printf("\n");
    for (int i = 0; i < this->height; i++)
    {
        for (int j = 0; j < this->width; j++)
        {
            // decide whether player is on this spot or not
            if (player->x == j && player->y == i)
            {
                printf("X");
            }
            else
            {
                printf("%c", this->map[i][j]);
            }
        }
        // end each row with a newline.
        printf("\n");
    }
}

/**
 * @brief Validates and performs a movement in a given direction
 *
 * @param this Maze struct
 * @param player The player's current position
 * @param direction The desired direction to move in
 */
void move(maze *this, coord *player, char direction)
{
}

/**
 * @brief Check whether the player has won and return a pseudo-boolean
 *
 * @param this current maze
 * @param player player position
 * @return int 0 for false, 1 for true
 */
int has_won(maze *this, coord *player)
{
}

int main(int argc, char *argv[])
{
    // check args
    if (argc != 2){
        printf("Usage: %s <name1> \n", argv[0]);
        exit(EXIT_ARG_ERROR);
    }
    // set up some useful variables (you can rename or remove these if you want)
    coord *player;
    maze *this_maze = malloc(sizeof(maze));
    FILE *file;

    // open and validate mazefile

    // read in mazefile to struct

    // maze game loop

    // win

    // return, free, exit
}