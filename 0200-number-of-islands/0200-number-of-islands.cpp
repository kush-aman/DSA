class Solution {
private:
    void bfs(vector<vector<char>>& grid,int row, int col, vector<vector<int>>& vis){
        int n = grid.size();
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
                if(delrow >= 0 && delrow < n && delcol >= 0 && delcol < m && grid[delrow][delcol] == '1' && !vis[delrow][delcol]){
                    vis[delrow][delcol] = 1;
                    q.push({delrow,delcol});
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
       int n = grid.size();
       int m = grid[0].size();
       int count = 0;
       vector<vector<int>> vis(n,vector<int>(m,0));
       for(int row = 0;row < n;row++){
        for(int col = 0;col < m;col++){
            if(!vis[row][col] && grid[row][col] == '1'){
                count++;
                bfs(grid,row,col,vis);
            }
        }
       }
       return count;
    }
};