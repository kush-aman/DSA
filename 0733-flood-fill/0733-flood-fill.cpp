class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vis[sr][sc] = 1;
        int curColor = image[sr][sc];
        image[sr][sc] = color;
        queue<pair<int,int>> q;
        q.push({sr,sc});
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int delrow = -1;delrow <= 1;delrow++){
                for(int delcol = -1;delcol <= 1;delcol++){
                    int currow = row + delrow;
                    int curcol = col + delcol;
                    if((delrow == 1 && delcol == 1) || (delrow == 1 && delcol == -1) || (delrow == -1 && delcol == 1) || (delrow == -1 && delcol == -1)) continue;
                    if(currow >= 0 && currow < n && curcol >= 0 && curcol < m && image[currow][curcol] == curColor && !vis[currow][curcol]){
                        vis[currow][curcol] = 1;
                        image[currow][curcol] = color;
                        q.push({currow,curcol});
                    }
                }
            }
        }
        return image;
    }
};