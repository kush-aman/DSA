class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int cur = 0, prev = 0;
        for(int i = 0;i < nums.size();i++){
            nums[i] = max(cur,nums[i] + prev);
            prev = cur;
            cur = nums[i];
        }

        return nums[nums.size() - 1];
    }
};