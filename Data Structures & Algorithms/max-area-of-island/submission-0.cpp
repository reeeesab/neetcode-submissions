class Solution {
public:
    int bfs(vector<vector<int>> &vis, vector<vector<int>> &grid, int i, int j){
        vis[i][j]=1;
        queue<pair<int, int>> q;
        q.push({i, j});
        int area = 1;
        int n = grid.size();
        int m = grid[0].size();
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            int deltaRow[] = {0, -1, 0, 1};
            int deltaCol[] = {-1, 0, 1, 0};
            for(int k = 0; k<4 ; k++){
                int nrow = row + deltaRow[k];
                int ncol = col + deltaCol[k];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                    area++;
                    q.push({nrow, ncol});
                    vis[nrow][ncol]=1;
                }

            }
        }

        return area;

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
       int n = grid.size();
       int m = grid[0].size();
       int maxArea = 0;
       vector<vector<int>> vis(n, vector<int>(m, 0));

       for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!vis[i][j] && grid[i][j]==1){
                    int area = bfs(vis, grid, i, j);
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};
