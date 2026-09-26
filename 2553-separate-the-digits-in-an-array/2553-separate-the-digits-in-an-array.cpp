class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int num : nums){
            vector<int> temp;
            while(num > 0){
                int remainder = num % 10;
                temp.push_back(remainder);
                num /= 10;
            }

            reverse(temp.begin(),temp.end());
            for(int i = 0;i < temp.size();i++){
                ans.push_back(temp[i]);
            }
        }
        return ans;
    }
};