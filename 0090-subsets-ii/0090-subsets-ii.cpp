class Solution {
public:
    void func(int ind, set<vector<int>>& ans, vector<int>& ds, vector<int> nums){
        if(ind == nums.size()){
            ans.insert(ds);
            return;
        }

        ds.push_back(nums[ind]);
        func(ind + 1, ans, ds, nums);
         ds.pop_back();
         func(ind + 1, ans, ds, nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> ans;
        vector<int> ds;
        func(0,ans, ds, nums);
        vector<vector<int>> finalAns{ans.begin(),ans.end()};

        return finalAns;
    }
};