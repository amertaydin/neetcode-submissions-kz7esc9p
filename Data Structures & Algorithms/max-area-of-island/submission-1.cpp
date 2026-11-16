class Solution {
    int ROW;
    int COL;
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        ROW = grid.size();
        COL = grid[0].size();

        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++) {
                if (grid[i][j] == 1) {
                    int area = dfs(i, j, grid);
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }

    int dfs(int row, int col, vector<vector<int>>& grid) {
        if (row < 0 || col < 0 || row >= ROW || col >= COL || grid[row][col] == 0) return 0;

        grid[row][col] = 0;
        
        int area = 1;

        area += dfs(row + 1, col, grid) +
        dfs(row - 1, col, grid) +
        dfs(row, col + 1, grid) +
        dfs(row, col - 1, grid);

        return area;
    }
};
