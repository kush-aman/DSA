class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];
        int ind = -1;
        for(int i = 1;i < nums.size();i++){
            if(nums[i - 1] + 1 == nums[i]){
                sum += nums[i];
            }
            else{
                ind = i;
                break;
            } 
        }
        sort(nums.begin(),nums.end());
        for(int i = 0;i < nums.size();i++){
            if(nums[i] == sum){
                sum++;
            }
        }
        return sum;
    }
};