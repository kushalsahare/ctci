/* Copyright
*/

#include <iostream>
#include <vector>

typedef std::vector<std::vector<bool> > grid_t;

void printHelper(const grid_t & board) {
        for (auto i : board) {
                for (auto j : i) {
                        std::cout << j << " ";
                }
                std::cout << "\n";
        }
}

bool getPath(grid_t & grid, grid_t & visited, int row, int col) {
  if (row >= 8 || col >= 8 || grid[row][col] || visited[row][col]) {
    return false;
  }
  visited[row][col] = true;

  if (row == 7 && col == 7) {
    return true;
  }

  if (getPath(grid, visited, row+1, col)
       || getPath(grid, visited, row, col+1)) {
    return true;
  }
return false;
}

bool Solve(grid_t &grid, grid_t & visited) {
  return getPath(grid, visited, 0, 0);
}

int main() {
  //  grid_t grid(8, std::vector<bool>(8, 0));
  grid_t visited(8, std::vector<bool> (8, false));
  grid_t grid {{0, 0, 1, 0, 0, 0, 1, 0},
               {0, 0, 1, 0, 0, 0, 1, 0},
               {0, 0, 1, 0, 0, 0, 1, 0},
               {0, 0, 0, 0, 1, 1, 1, 0},
               {0, 0, 0, 0, 0, 1, 0, 0},
               {1, 1, 0, 0, 0, 1, 0, 0},
               {0, 0, 1, 0, 0, 0, 0, 0},
               {0, 0, 1, 0, 0, 1, 0, 0}};
//  printHelper(grid);
  bool t = Solve(grid, visited);
  if (t) {
  printHelper(grid);
  std::cout << "\n";
  printHelper(visited);
} else {
  printHelper(visited);
  std::cout << "Can't";
}
  return 0;
}
