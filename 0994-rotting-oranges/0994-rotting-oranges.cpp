class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cntfresh = 0;
        queue<pair<pair<int,int>,int>> q;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                }
                if(grid[i][j] == 1) cntfresh++;
            }
        }
        vector<int> dx = {-1,0,1,0};
        vector<int> dy = {0,1,0,-1};
        int time = 0;
        int cnt = 0;
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            time = max(time,t);
            q.pop();
            for(int i = 0;i < 4;i++){
                int delrow = row + dx[i];
                int delcol = col + dy[i];
                if(delrow >= 0 && delrow < n && delcol >= 0 && delcol < m && grid[delrow][delcol] == 1){
                    grid[delrow][delcol] = 2;
                    q.push({{delrow,delcol},t+1});
                    cntfresh--;
                }
            }
        }
        if(cntfresh != 0) return -1;

        return time;
    }
};