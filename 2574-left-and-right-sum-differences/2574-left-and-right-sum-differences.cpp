class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftSum(n,0),rightSum(n,0);
        int sum = 0;
        for(int i = 0;i < nums.size();i++){
           leftSum[i] += sum;
           sum += nums[i];
        }
        sum = 0;
        for(int i = nums.size() - 1;i >= 0;i--){
            rightSum[i] += sum;
            sum += nums[i];
        }
        vector<int> ans(n,0);
        for(int i = 0;i < n;i++){
            ans[i] += abs(leftSum[i] - rightSum[i]);
        }
        return ans;
    }
};