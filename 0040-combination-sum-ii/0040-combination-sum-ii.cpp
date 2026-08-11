class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(),candidates.end());
        func(0, candidates, target, ans, ds);

        return ans;
    }
    void func(int index, vector<int>& arr, int target, vector<vector<int>>& ans, vector<int>& ds){
        if(target == 0){
            ans.push_back(ds);
            return;
        }

        for(int i = index; i < arr.size();i++){
            if(i > index && arr[i] == arr[i-1]) continue;
            if(arr[i] > target) break;
            ds.push_back(arr[i]);
            func(i + 1, arr, target - arr[i], ans, ds);
            ds.pop_back();
        }
    }
};