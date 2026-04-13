class Solution {
    int ROW = 0;
    int COL = 0;
public:
    int numIslands(vector<vector<char>>& grid) {
        ROW = grid.size(); 
        COL = grid[0].size();
        int numIslands = 0;

        for (int r = 0; r < ROW; r++) {
            for (int c = 0; c < COL; c++) {
                if (grid[r][c] == '1') {
                    dfs(r, c, grid);
                    numIslands++;
                }
            }
        }

        return numIslands;
    }

    void dfs(int r, int c, vector<vector<char>>& grid) {

        if (r < 0 || c < 0 || r >= ROW || c >= COL || grid[r][c] == '0')
            return;

        grid[r][c] = '0';

        dfs(r + 1, c, grid);
        dfs(r - 1, c, grid);
        dfs(r, c + 1, grid);
        dfs(r, c - 1, grid); 
    }
};
