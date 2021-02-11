#include "Pathfinder.h"

int main() {
    Pathfinder pathfinder{};
    string filename = "./Mazes/Solvable1.txt";
//    pathfinder.importMaze(filename);
pathfinder.createRandomMaze();
    string maze = pathfinder.toString();
    cout << maze;

    return 0;
}