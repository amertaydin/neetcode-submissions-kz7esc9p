class Solution {
    bool flag = false;
public:
    bool exist(vector<vector<char>>& board, string word) {
        string str;
        int row = board.size();
        int col = board[0].size();

        // I need to try every possible scenarios from every cell
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (dfs(i, j, board, word, 0)) return true;
            }
        }

        return false;
    }

    bool dfs(int row, int col, vector<vector<char>>& board, string word, int idx) {
        int ROW = board.size();
        int COL = board[0].size();
        if (idx == word.size()) return true; // base statement
        if (row < 0 || col < 0 || row >= ROW || col >= COL || board[row][col] != word[idx] ) return false;

        board[row][col] = '*'; 
       bool res = dfs(row + 1, col, board, word, idx + 1) ||
        dfs(row - 1, col, board, word, idx + 1) ||
        dfs(row, col + 1, board, word, idx + 1) ||
        dfs(row, col - 1, board, word, idx + 1);
        board[row][col] = word[idx];
        
        return res;
    }
};
