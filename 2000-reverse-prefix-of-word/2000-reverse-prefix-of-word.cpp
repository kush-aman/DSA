class Solution {
public:
    string reversePrefix(string word, char ch) {
        int left = 0;
        int i = 0;
        int right = 0;
        for(int i = 0;i < word.size();i++){
            if(word[i] == ch){
                right = i;
                reverse(word.begin(),word.begin() + right + 1);
                break;
            }
        }
        return word;
    }
};