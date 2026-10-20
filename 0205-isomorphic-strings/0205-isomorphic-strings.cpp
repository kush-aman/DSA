class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        int indexS[256] = {0};
        int indexT[256] = {0};
        for(int i = 0;i< s.size();i++){
            if(indexS[s[i]] != indexT[t[i]]) return false;
            indexS[s[i]] = i+1;
            indexT[t[i]] = i+1;
        }
        return true;
    }
};