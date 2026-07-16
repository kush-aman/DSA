class Solution {
public:
    void func(int index, set<vector<int>>& ans, vector<int> nums){
        if(index == nums.size()){
            ans.insert(nums);
            return;
        }

        for(int i = index; i < nums.size();i++){
            swap(nums[index],nums[i]);
            func(index + 1, ans, nums);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> ans;
        func(0, ans, nums);
        vector<vector<int>> final(ans.begin(),ans.end());
        return final;
    }
};