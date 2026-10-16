class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        int count = 0;
        char el = s[0];
        for(int i = 0;i < s.size();i++){
            if(s[i] == el){
                count++;
                if(count < 3){
                    ans.push_back(s[i]);
                }
            }
            else{
                count = 1;
                el = s[i];
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};