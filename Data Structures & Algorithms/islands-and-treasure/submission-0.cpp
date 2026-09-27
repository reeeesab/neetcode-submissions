class Solution {
public:
    void bfs(vector<vector<int>>& grid,
            vector<vector<int>>& vis,
            queue<pair<int,int>>& q) {

        int n = grid.size();
        int m = grid[0].size();

        int cnt = 1;

        int deltaRow[] = {-1, 0, 1, 0};
        int deltaCol[] = {0, 1, 0, -1};

        while(!q.empty()) {

            int size = q.size();
            bool changed = false;

            for(int i = 0; i < size; i++) {

                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                for(int k = 0; k < 4; k++) {

                    int nrow = row + deltaRow[k];
                    int ncol = col + deltaCol[k];

                    if(nrow >= 0 && nrow < n &&
                       ncol >= 0 && ncol < m &&
                       !vis[nrow][ncol] &&
                       grid[nrow][ncol] == 2147483647) {
                        q.push({nrow, ncol});
                        vis[nrow][ncol] = 1;
                        grid[nrow][ncol] = cnt;
                        changed = true;
                    }
                }
            }

            if(changed) cnt++;
        }
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
       bfs(grid, vis, q);
    }
};
