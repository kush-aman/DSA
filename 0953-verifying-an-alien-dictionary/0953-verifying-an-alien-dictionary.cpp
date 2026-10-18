class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char,int> mpp;
        for(int i = 0;i < order.size();i++){
            mpp[order[i]] = i;
        }
        for(int i = 0;i < words.size() - 1;i++){
            string str1 = words[i];
            string str2 = words[i+1];
            int len = min(str1.size(),str2.size());
            int flag = 0;
            for(int ptr = 0; ptr < len;ptr++){
                if(str1[ptr] != str2[ptr] && mpp[str1[ptr]] > mpp[str2[ptr]]) return false;
                else if(str1[ptr] != str2[ptr] && mpp[str1[ptr]] < mpp[str2[ptr]]){
                    flag = 1;
                    break;
                }
            }
            if(flag == 0 && str1.size() > str2.size()) return false;
        }
        return true;
    }
};