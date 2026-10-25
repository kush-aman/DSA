class Solution {
public:
void bfs(int row, int col,vector<vector<int>> grid,vector<vector<int>>& vis){
    int n =grid.size();
    int m = grid[0].size();

    vis[row][col] = 1;
        vector<int> dx = {-1,1,0,0};
        vector<int> dy = {0,0,-1,1};
        queue<pair<int,int>> q;
        q.push({row,col});
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i = 0;i < 4;i++){
                int delrow = row + dx[i];
                int delcol = col + dy[i];
                if(delrow >= 0 && delrow < n && delcol >= 0 && delcol < m && grid[delrow][delcol] == 0 && !vis[delrow][delcol]){
                    vis[delrow][delcol] = 1;
                    q.push({delrow,delcol});
                }
            }
        }
}
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<int>> vis(n,vector(m,0));
        queue<pair<int,int>> q;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(i == 0 || i == n - 1 || j == 0 || j == m - 1){
                    if(grid[i][j] == 0){
                        q.push({i,j});
                        vis[i][j] = 1;
                    }
                }
            }
        }
        vector<int> dx = {-1,1,0,0};
        vector<int> dy = {0,0,-1,1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i = 0; i< 4;i++){
                int delrow = row + dx[i];
                int delcol = col + dy[i];
                if(delrow >= 0 && delrow < n && delcol >= 0 && delcol <m && !vis[delrow][delcol] && grid[delrow][delcol] == 0){
                    vis[delrow][delcol] = 1;
                    q.push({delrow,delcol});
                }
            }
        }
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(!vis[i][j] && grid[i][j] == 0){
                    count++;
                    bfs(i,j,grid,vis);
                }
            }
        }
        return count;
    }
};