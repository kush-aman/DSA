class Solution {
public:
    string largestOddNumber(string num) {
        string ans = "";
        
        for(int i = num.size() - 1;i >= 0;i--){
            if(static_cast<int>(num[i]) % 2 == 1){
                int j = 0;
                int index = i;
                while(j <= index){
                    ans.push_back(num[j]);
                    j++;
                }
                break;
            }
        }
        return ans;
    }
};