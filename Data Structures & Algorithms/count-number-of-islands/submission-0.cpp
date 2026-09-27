class Solution {
public:
    void bfs(int row, int col, vector<vector<char>>&grid, vector<vector<int>>&vis){
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        int n = grid.size();
        int m = grid[0].size();
        while(!q.empty()){
            int nrow = q.front().first;
            int ncol = q.front().second;
            q.pop();
            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, 1, 0, -1};
           for(int i = 0; i<4; i++){
                    int nnrow = nrow + dr[i];
                    int nncol = ncol + dc[i];

                    if(nnrow>=0 && nnrow<n && nncol>=0 && nncol<m && !vis[nnrow][nncol] && grid[nnrow][nncol]=='1'){
                        vis[nnrow][nncol]=1;
                        q.push({nnrow, nncol});
                    }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int cnt = 0;
        vector<vector<int>> vis(row, vector<int>(col, 0));
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    cnt++;
                    bfs(i, j, grid, vis);
                }
            }
        }
        return cnt;
    }
};
