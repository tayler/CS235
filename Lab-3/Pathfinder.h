#ifndef LAB_3_PATHFINDER_OLD_H
#define LAB_3_PATHFINDER_OLD_H

#include <vector>
#include <fstream>
#include <sstream>

#include "PathfinderInterface.h"

using namespace std;
class Pathfinder : public PathfinderInterface {
private:
    static const int ROW_SIZE = 5;
    static const int COL_SIZE = 5;
    static const int LEVEL_SIZE = 5;
    const int BACKGROUND = 1;
    const int WALL = 0;
    const int TEMPORARY = 2; // Used to show this path has been explored
    const int PATH = 3;
    int maze_grid[ROW_SIZE][COL_SIZE][LEVEL_SIZE]; // To hold values
    vector<string> solution;
public:
    // constructor
    Pathfinder() {
        srand(time(nullptr));
    }

    string toString() const {
        stringstream ss;
        for (int level = 0; level < LEVEL_SIZE; level++) {
            for (int row = 0; row < ROW_SIZE; row++) {
                for (int col = 0; col < COL_SIZE; col++) {
                    ss << maze_grid[row][col][level];
                    if (col < COL_SIZE - 1) {
                        ss << ' ';
                    }
                }
                ss << endl;
            }
            ss << endl;
        }

        return ss.str();
    }

    void createRandomMaze() {
        for (int level = 0; level < LEVEL_SIZE; level++) {
            for (int row = 0; row < ROW_SIZE; row++) {
                for (int column = 0; column < COL_SIZE; column++) {
                    maze_grid[row][column][level] = rand() % 2;
                }
            }
        }
    }

    bool importMaze(string file_name)
    {
        cout << "importMaze from "<<file_name<<endl;
        ifstream file (file_name.c_str());
        if (file.is_open()) {
            string line;
            for (int level = 0; level < LEVEL_SIZE; level++) {
                for (int row = 0; row < ROW_SIZE; row++) {
                    getline(file, line);
                    stringstream ss(line);
                    cout << "ss.str(): '" << ss.str() <<"';" << endl;
                    if (ss.str() == "") {
                        // if the line is blank, get the following line
                        getline(file, line);
                        ss.str(line);
                    }
                    for (int col = 0; col < COL_SIZE; col++) {
                        int value;
                        ss >> value;
                        cout << "["<<row<<"]["<<col<<"]["<<level<<"]="<<value<<endl;
                        maze_grid[row][col][level] = value;
                    }
                    cout << "end of Row" << endl;
                }
                cout << "end of level" << endl;
            }
        }
        return(true);
    }

    vector<string> solveMaze() {
        return solution;
    }
};
#endif //LAB_3_PATHFINDER_OLD_H
