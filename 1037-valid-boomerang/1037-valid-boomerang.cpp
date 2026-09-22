class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        int n = points.size();
        int m = points[0].size();
        int x0 = points[0][0];
        int y0 = points[0][1];
        int x1 = points[1][0];
        int y1 = points[1][1];
        for(int i = 2;i< n;i++){
            int x = points[i][0];
            int y = points[i][1];
            if((x - x0) * (y1 - y0) != (y - y0) * (x1 - x0)) return true;
        }
        return false;
    }
};