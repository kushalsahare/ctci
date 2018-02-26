/* Copyright
*/

#include <iostream>
#include <vector>


typedef std::vector<std::vector<bool> > board_t;

//  using namespace std;

void printBoard(const board_t & board) {
        for (auto i : board) {
                for (auto j : i) {
                        std::cout << j << " ";
                }
                std::cout << "\n";
        }
}

bool isSafe(const board_t board, int row, int col) {
  int i, j;
  for (i = 0 ; i < col; ++i) {
    if (board[row][i] == true)
    return false;
  }

  for ( i = row, j = col; i > -1 && j > -1; --i, --j ) {
    if (board[i][j] == true)
    return false;
  }

  for ( i = row, j = col; i < 8 && j > -1; ++i, --j ) {
    if (board[i][j] == true)
    return false;
  }
  return true;
}

/*void updateAttack(status_t & status, int row, int col) {
        int i = 0;
        int j = 0;
        for (i = 0; i < 8 ; i++) {
                status[i][col] = true;
        }
        for (j = 0; j < 8; j++) {
                status[row][j] = true;
        }
        // left top
        i = row-1;
        j = col-1;
        while (i > -1 && j > -1) {
        //  std::cout << i << " " << j << "\n";
                status[i][j] = true;
                --i;
                --j;
        }
        //  right top
        i = row-1;
        j = col+1;
        while (i > -1 && j < 8) {
          status[i][j] = true;
          --i;
          ++j;
        }
        // left bottom
        i = row+1;
        j = col-1;

        while (i < 8 && j > -1) {
          status[i][j] = true;
          ++i;
          --j;
        }
        // right bottom
        i = row+1;
        j = col+1;
        while (i < 8 && j < 8) {
         status[i][j] = true;
         ++i;
         ++j;
        }
        return;
}*/

bool SolveNQUtil(board_t& board, int col) {
  if (col >= 8) return true;

  for (int i = 0; i < 8; ++i) {
    if (isSafe(board, i, col)) {
      board[i][col] = true;
      if (SolveNQUtil(board, col+1)) {
        return true;
      }
      board[i][col] = false;
    }
  }
  return false;
}
bool SolveNQ(board_t& board, int col) {
  return SolveNQUtil(board, col);
}

int main() {
  board_t board(8, std::vector<bool>(8, false));
  bool t = SolveNQ(board, 0);
  if (t) {
    printBoard(board);
}
        std::cout << "print exit \n";
        return 0;
}
