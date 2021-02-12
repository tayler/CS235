#ifndef LAB_3_PATHFINDER_OLD_H
#define LAB_3_PATHFINDER_OLD_H

#include <vector>
#include <fstream>
#include <sstream>

#include "PathfinderInterface.h"

using namespace std;
typedef int int3D[5][5][5];
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
    int copy_maze_grid[ROW_SIZE][COL_SIZE][LEVEL_SIZE]; // To hold values
    vector<string> solution;
public:
    // constructor
    Pathfinder() {
        srand(time(nullptr));
        // initialize grids
        resetMaze();
    }

    void resetMaze() {
        for (int level = 0; level < LEVEL_SIZE; level++) {
            for (int row = 0; row < ROW_SIZE; row++) {
                for (int col = 0; col < COL_SIZE; col++) {
                    maze_grid[row][col][level] = 1;
                }
            }
        }
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
            if (level < LEVEL_SIZE - 1) {
                ss << endl;
            }
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
        maze_grid[0][0][0] = 1;
        maze_grid[4][4][4] = 1;
    }

    bool importMaze(string file_name) {
        cout << "importMaze from "<<file_name<<endl;
        ifstream file (file_name.c_str());
        int count1 = 0;
        int count0 = 0;
        if (!file.is_open()) {
            cout << "Could not open maze file." << endl;
            return false;
        } else {
            int record_count = 0;
            string count_line;
            while (getline(file, count_line))
            {
                ++record_count;
            }
            if (record_count != 29) {
                resetMaze();
                cout << "Invalid maze. Maze is under or over max size." << endl;
                return false;
            }
            // reset file so we can go through each line again
            file.clear();
            file.seekg(0);

            string line;
            for (int level = 0; level < LEVEL_SIZE; level++) {
                for (int row = 0; row < ROW_SIZE; row++) {
                    getline(file, line);
                    stringstream ss(line);
//                    cout << "ss.str(): '" << ss.str() <<"';" << endl;
                    if (ss.fail()) {
                        cout << "Invalid maze. All maze values must be 1 or 0." << endl;
                        return(false);
                    }
                    if (ss.str() == "") {
                        // if the line is blank, get the following line
                        getline(file, line);
                        ss.str(line);
                    }
                    for (int col = 0; col < COL_SIZE; col++) {
                        int value;
                        ss >> value;

                        // test for valid maze
//                        if (ss.str() != "1" && ss.str() != "0") {
//                            cout << "'" << value << "'";
//
//                            resetMaze();
//                            return false;
//                        }
                        if (value == 1) {
                            count1++;
                        }
                        else if (value == 0) {
                            count0++;
                        }
                        maze_grid[row][col][level] = value;
                        copy_maze_grid[row][col][level] = value;
                    }
                        line.clear();
//                    cout << "end of Row" << endl;
                }
//                cout << "end of level" << endl;
            }
//            else if (count0 == 0 || count1 == 0) {
//                cout << count0 << endl;
//                cout << count1 << endl;
//                resetMaze();
//                cout << "Invalid maze. The maze is either entirely 1s or 0s." << endl;
//                return false;

            if (maze_grid[0][0][0] != 1 || maze_grid[4][4][4] != 1) {
                resetMaze();
                cout << "Invalid maze. The maze must begin and end on 1." << endl;
                return false;
            }
        }
        return(true);
    }

    bool findMazePath(int grid[ROW_SIZE][COL_SIZE][LEVEL_SIZE], int r, int c, int l) {
//        cout << "findMazePath ["<<r<<"]["<<c<<"]["<<l<<"]"<<endl;
//        cout << this->toString();
        // Cell is out of bounds
        int origValue = grid[r][c][l];
        if (r < 0 || c < 0 || l < 0 || r >= ROW_SIZE || c >= COL_SIZE || l >= LEVEL_SIZE) {
            return false;
        }
        // Cell is on barrier or dead end
        else if (grid[r][c][l] != BACKGROUND) {
            return false;
        }
        // Maze exit (4,4,4)
        else if (r == ROW_SIZE - 1 && c == COL_SIZE - 1 && l == LEVEL_SIZE - 1) {
//            grid[r][c][l] = PATH;
            solution.push_back("("+to_string(r)+", "+to_string(c)+", "+to_string(l) + ")");
            return true;
        }
        else {
            // Recursive case.
            // Attempt to find a path from each neighbor.
            // Tentatively mark cell as on path.
            grid[r][c][l] = PATH;
            if (
                this->findMazePath(grid, r - 1, c, l) // N
                || this->findMazePath(grid, r + 1, c, l) // S
                || this->findMazePath(grid, r, c + 1, l) // E
                || this->findMazePath(grid, r, c - 1, l) // W
                || this->findMazePath(grid, r, c, l - 1) // Up
                || this->findMazePath(grid, r, c, l + 1) // Down
            ) {
                solution.push_back("("+to_string(r)+", "+to_string(c)+", "+to_string(l) + ")");
                grid[r][c][l] = origValue;
                return true;
            }
            else {
                grid[r][c][l] = TEMPORARY;  // Dead end.
                return false;
            }
        }
    }

    vector<string> solveMaze() {
        bool solved = this->findMazePath(copy_maze_grid, 0, 0, 0);
        vector<string> reverseSolution;
        if (solved == false) {
            cout << "Maze unsolvable. No solution found." << endl;
        }
        else {
            cout << "Maze solved! Solution:" << endl;
//            for (int i = solution.size() - 1; i >= 0; i--) {
//                // print solution in order
//                reverseSolution.push_back(solution[i]);
//            }
//            for(auto s : solution) {
//                cout << s << endl;
//            }
        }
        return reverseSolution;
    }

    // destructor
    ~Pathfinder() {
        solution.clear();
    }
};
#endif //LAB_3_PATHFINDER_OLD_H
