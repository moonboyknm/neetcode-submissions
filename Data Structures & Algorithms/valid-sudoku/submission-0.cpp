class Solution{
  public:
    bool isValidSudoku(vector<vector<char>>& board){
      // Traversing the Rows.
      for(int row = 0; row < 9; row++){
        // If element found in seen, there exists a duplicate.
        unordered_set<char> seen;
        for(int i = 0; i < 9; i++){
          if(board[row][i] == '.') continue;
          if(seen.count(board[row][i])) return false;
          seen.insert(board[row][i]);
        }
      }

      // Traversing the Columns.
      for(int col = 0; col < 9; col++){
          unordered_set<char> seen;
        for(int i = 0; i < 9; i++){
          if(board[i][col] == '.') continue;
          if (seen.count(board[i][col])) return false;
          seen.insert(board[i][col]);
        }
      }

      // box represents the elements inside a 3x3 sub-square of the sudoku.
      for(int box = 0; box < 9; box++){
        unordered_set<char> seen; 
        for(int i = 0; i < 3; i++){
          for(int j = 0; j < 3; j++){
            int row = (box / 3) * 3 + i;
            int col = (box % 3)* 3 + j;
            if(board[row][col] == '.') continue;
            if(seen.count(board[row][col])) return false;
            seen.insert(board[row][col]);
          }
        }
      }

      return true;
    }
};