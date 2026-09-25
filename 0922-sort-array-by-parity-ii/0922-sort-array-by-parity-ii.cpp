class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int j = 1;
        for(int i = 0; i < nums.size();i+=2){
            if(nums[i] % 2 == 0) continue;
            else{
                while(true){
                    if(nums[j] % 2 == 0){
                        swap(nums[i],nums[j]);
                        break;
                    }
                    j += 2;
                }
            }
        }
        return nums;
    }
};