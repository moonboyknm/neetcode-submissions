class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
      //Traversing Rows 
        for(int row = 0; row < 9; row++){
          unordered_set<char> seen;
          for(int mover = 0; mover < 9; mover++){
            if(board[row][mover] == '.') continue;
            if(seen.count(board[row][mover])) return false;
            seen.insert(board[row][mover]);
          }
        }

      //Traversing Columns
      for(int col = 0; col < 9; col++){
        unordered_set<char> seen;
        for(int mover = 0; mover < 9; mover++){
          if(board[mover][col] == '.') continue;
          if(seen.count(board[mover][col])) return false;
          seen.insert(board[mover][col]);
        }
      }

      //Traversing Board
      for(int box = 0; box < 9; box++){
        unordered_set<char> seen;
        for(int i = 0; i < 3; i++){
          for(int j = 0; j < 3; j++){
            int row = (box / 3) * 3 + i;
            int col = (box % 3) * 3 + j;

            if(board[row][col] == '.') continue;
            if(seen.count(board[row][col])) return false;

            seen.insert(board[row][col]);
          }
        }
      }

      return true;

    }
};

