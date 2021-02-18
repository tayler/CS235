#include "Pathfinder.h"

int main(int argc, char *argv[]) {
    Pathfinder pathfinder{};
//    string filename = "./Mazes/Solvable2.txt";
    string filename = "./Mazes/" + string(argv[1]) + ".txt";
    bool success = pathfinder.importMaze(filename);
    if (success) {
        vector<string> solution = pathfinder.solveMaze();
    }
//pathfinder.createRandomMaze();
//    string maze = pathfinder.toString();
//    cout << maze;


    return 0;
}