class Solution {
public:
    void func(set<vector<int>>& ans, vector<int>& ds, vector<int> nums, int freq[]){
        if(ds.size() == nums.size()){
            ans.insert(ds);
            return;
        }

        for(int i = 0; i < nums.size();i++){
            if(!freq[i]){
                ds.push_back(nums[i]);
                freq[i] = 1;
                func(ans, ds, nums, freq);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> ds;
        int freq[nums.size()];
        for(int i =0; i< nums.size();i++) freq[i] = 0;

        func(ans, ds, nums, freq);

        vector<vector<int>> finalAns(ans.begin(),ans.end());
        return finalAns;
    }
};