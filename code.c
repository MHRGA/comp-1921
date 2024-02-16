typedef struct {
    int width;
    int height;
    int start;
    int end;
    PLAYER character;
} MAZE;

typedef struct {
    int position;
} PLAYER;

int check_cell(int new_position, MAZE maze) {
    // check if new space is not wall
    // if wall, prompt user and return 1
    // check if new space is end position (goal)
    // if end, prompt user they won and exit program
    // else return 0
}

char open_map(char *maze) {
    // print 2d array to user
}

void move_character(PLAYER player, char *map) {
    // call check cell function
    // if check cell returns 1, exit this function
    // update struct details
    // update 2d array map
}

void read_from_file(int input) {
    // error checking to make sure file exists
    // if file doesnt exist, throw error and exit program
    // open file
    // copy contents of file into struct
    // check if file is valid (width and height meet requirements)
    // if not, throw error and exit program
}

int main(int argc, char *argv[]) {
    // store command line argument as filename
    // call function read_from_file
    // show map to user
    // start user at start position
    // infinite while loop
        // ask user for input
        // switch statement for moving in four directions or opening map
        // call relevent function (move_character for WASD and open_map for M)
    return 0;
}