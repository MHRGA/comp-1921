/**
 * @brief Initialise a maze object - allocate memory and set attributes
 *
 * @param this pointer to the maze to be initialised
 * @param height height to allocate
 * @param width width to allocate
 * @return int 0 on success, 1 on fail
 */
int create_maze(maze *this, char *filename, int height, int width)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("%s", "Error: Could not find or open the file.\n");
        exit(EXIT_FILE_ERROR);
    }
    this->height = height;
    this->width = width;
    int buffer_size = 100;
    char line_buffer[buffer_size];
    while (fgets(line_buffer, buffer_size, file) != '\n') {
        for(int i = 0; i < this->height; i++) {
            for(int j=0; j < this->width; j++) {
                if(line_buffer[j] == 'S') {
                    coord start = {i,j};
                    this->start = start;
                }
                if(line_buffer[j] == 'E') {
                    coord end = {i,j};
                    this->end = end;
                }

            }
        }
    }
}


create_maze(this_maze, argv[1], this_maze->height, this_maze->width);