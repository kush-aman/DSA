class Solution {
public:
    void rowWise(vector<vector<int>>& mat,int row){
        for(int i = 0;i < mat[0].size();i++){
            mat[row][i]++;
        }
    }
    void colWise(vector<vector<int>>& mat,int col){
        for(int i = 0;i < mat.size();i++){
            mat[i][col]++;
        }
    }
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<vector<int>> mat(m,vector(n,0));

        for(int i = 0;i < indices.size();i++){
            rowWise(mat,indices[i][0]);
            colWise(mat,indices[i][1]);
        }
        int count = 0;
        for(int i = 0;i < mat.size();i++){
            for(int j = 0;j < mat[0].size();j++){
                if(mat[i][j] % 2 == 1) count++;
            }
        }
        return count;
    }
};