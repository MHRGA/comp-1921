/**
 * @file maze.c
 * @author MUHAMAD HEWA RAHIM
 * @brief Code for the maze game for COMP1921 Assignment 2
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
int create_maze(maze *this, char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("%s", "Error: Could not find or open the file.\n");
        exit(EXIT_FILE_ERROR);
    }
    this->map = (char**)malloc(this->height * sizeof(char*));
    for (int i = 0; i < this->height; i++) {
        this->map[i] = (char*)malloc(this->width * sizeof(char*));
    }
    int i = 0;
    char next_char;
    while (!(feof(file))) {
        for (int j = 0; j < this->width; j++) {
            if(fscanf(file, "%1[^\n]%*[\n]", &this->map[i][j]) == '\n') {
                break;
            }
        }
        i++;
        if (i == this->height) {
            break;
        }
    }
    for (int i = 0; i < this->height; i++) {
        for (int j = 0; j < this->width; j++) {
            printf("%c", this->map[i][j]);
            if (this->map[i][j] == 'S') {
                coord start = {i,j};
                this->start = start;
            }
            else if (this->map[i][j] == 'E') {
                coord end = {i,j};
                this->end = end;
            }
        }
        printf("\n");
    }
    printf("Start = (%d,%d)\n", this->start.x, this->start.y);
    printf("End = (%d,%d)\n", this->end.x, this->end.y);
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
int get_width(char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not find or open the file.\n");
        exit(EXIT_FILE_ERROR);
    }
    int maze_width = 0;
    int first_width = NULL;
	int buffer_size = 100;
    char line_buffer[buffer_size];
    while (fgets(line_buffer, buffer_size, file) != NULL) {
        maze_width = 0;
        for (int i = 0; line_buffer[i] != '\0'; i++) {
            if (line_buffer[i] != '\n') {
                maze_width++;
            }
        }
        if (first_width == NULL) {
            first_width = maze_width;
        }
        else if (maze_width != first_width) {
            return 0;
        }
    }
    if (maze_width < MIN_DIM || maze_width > MAX_DIM) {
        return 0;
    }
    fclose(file);
    return maze_width;
}

/**
 * @brief Validate and return the height of the mazefile
 *
 * @param file the file pointer to check
 * @return int 0 for error, or a valid height (5-100)
 */
int get_height(char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not find or open the file.\n");
        exit(EXIT_FILE_ERROR);
    }
    int maze_height = 0;
	int buffer_size = 100;
    char line_buffer[buffer_size];
    while (fgets(line_buffer, buffer_size, file) != NULL) {
        maze_height++;
    }
    if (maze_height < MIN_DIM || maze_height > MAX_DIM) {
        return 0;
    }
    fclose(file);
    return maze_height;
}

void valid_characters(char *filename)
{
    int character;
    int start_char = 0;
    int end_char = 0;
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not find or open the file.\n");
        exit(EXIT_FILE_ERROR);
    }
    while ((character = getc(file)) != EOF) {
        if (character != 'S' && character != 'E' && character != '#' && character != ' ' && character != '\n') {
            printf("Error: Invalid maze file. cc");
            exit(EXIT_MAZE_ERROR);
        }
        if (character == 'S') {
            start_char++;
            if (start_char > 1) {
                printf("Error: Invalid maze file. se");
                exit(EXIT_MAZE_ERROR);
            }
        }
        if (character == 'E') {
            end_char++;
            if (end_char > 1) {
                printf("Error: Invalid maze file. se");
                exit(EXIT_MAZE_ERROR);
            }
        }
    }
    if (start_char == 0 || end_char == 0) {
        printf("Error: Invalid maze file. se");
        exit(EXIT_MAZE_ERROR);
    }
    fclose(file);
}

/**
 * @brief read in a maze file into a struct
 *
 * @param this Maze struct to be used
 * @param file Maze file pointer
 * @return int 0 on success, 1 on fail
 */
int read_maze(maze *this, char *filename)
{
    int height = get_height(filename);
    int width = get_width(filename);
    printf("%d %d \n", height, width);
    if (height == 0 || width == 0) {
        printf("Error: Invalid maze file. hw\n");
        printf("%d %d", height, width);
        exit(EXIT_MAZE_ERROR);
    }
    valid_characters(filename);
    this->height = height;
    this->width = width;
    return 0;
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

    // open and validate mazefile
    read_maze(this_maze, argv[1]);

    // read in mazefile to struct
    create_maze(this_maze, argv[1]);

    // maze game loop

    // win

    // return, free, exit
}