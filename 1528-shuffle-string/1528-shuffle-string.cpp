class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
       if(s.size() != indices.size()) return "";

       string ans = s;
       int j = 0;
       for(int i = 0;i < indices.size();i++){
            ans[indices[i]] = s[i];
       } 
       return ans;
    }
};