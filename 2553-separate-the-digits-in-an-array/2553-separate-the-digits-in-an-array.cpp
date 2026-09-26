class Solution {
private:
    void helper(int val, vector<int> nums, vector<int>& ans){
        string v = to_string(val);
        for(auto c : v){
            ans.push_back(c - '0');
        }
    }
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0;i < nums.size();i++){
            helper(nums[i],nums,ans);
        }
        return ans;
    }
};