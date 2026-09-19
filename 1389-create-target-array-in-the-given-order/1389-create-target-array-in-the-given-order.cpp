class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
      int n = nums.size();
      vector<int> ans(n);
      for(int i = 0;i < n;i++){
        int j = n-1;
        while(j > index[i]){
            swap(ans[j],ans[j-1]);
            j--;
        }
        ans[index[i]] = nums[i];
      }  
      return ans;
    }
};