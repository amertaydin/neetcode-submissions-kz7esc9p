class Solution {
    int ROW;
    int COL;
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        ROW = grid.size();
        COL = grid[0].size();

        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++) {
                if (grid[i][j] == '1') {
                    dfs(i, j, grid);
                    count++;
                }
            }
        }

        return count;
    }

    void dfs(int row, int col, vector<vector<char>>& grid) {
        if (row < 0 || col < 0 || row >= ROW || col >= COL || grid[row][col] == '0') return;

        grid[row][col] = '0'; 

        dfs(row + 1, col, grid);
        dfs(row - 1, col, grid);
        dfs(row, col + 1, grid);
        dfs(row, col - 1, grid);


    }
};
