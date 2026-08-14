class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans = INT_MAX,difffinal=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int j=i+1,k=nums.size()-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                int diff = abs(target-sum);
                difffinal = min(diff,difffinal);
                if(difffinal==diff){
                    ans = sum;
                }
                if(sum==target){
                    return target;
                }
                else if(sum<target){
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        return ans;
    }
};