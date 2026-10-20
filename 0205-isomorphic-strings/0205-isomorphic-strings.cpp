class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        map<char,int> indexS;
        map<char,char> indexT;
        for(int i = 0;i< s.size();i++){
            if(indexS.find(s[i]) == indexS.end()){
                indexS[s[i]] = i;
            }
            if(indexT.find(t[i]) == indexT.end()){
                indexT[t[i]] = i;
            }
            if(indexS[s[i]] != indexT[t[i]]) return false;
        }
        return true;
    }
};