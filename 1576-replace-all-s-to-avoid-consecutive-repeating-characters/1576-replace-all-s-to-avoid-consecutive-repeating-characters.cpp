class Solution {
public:
    string modifyString(string s) {
        for(int i = 0;i < s.size();i++){
            if(s[i] == '?'){
                for(char j = 'a';j <= 'z';j++){
                    if(i-1 >= 0 && j == s[i-1]) continue;
                    if(i+1 <= s.size() && j == s[i+1]) continue;
                    s[i] = j;
                    break;
                }
            }  
        }
        return s;
    }
};