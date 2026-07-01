class Solution {
public:
    int lowerBound(vector<int> arr, int x){
        int low = 0;
        int high = arr.size() - 1;
        int ans;
        while(low <= high){
            int mid = (low + high) / 2;
            if(arr[mid] >= x){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
vector<int> rowAndMaximumOnes(vector<vector<int>> &mat) {
    int n = mat.size();
    int m = mat[0].size();
    for(int i = 0; i < n;i++){
        sort(mat[i].begin(),mat[i].end());
    }
        int cntMax = 0;
        int index = 0;
        for(int i = 0;i < n;i++){
            int cntOnes = m - lowerBound(mat[i],1);
            if(cntOnes > cntMax){
                cntMax = cntOnes;
                index = i;
            }
        }
    return {index,cntMax};
    }
};