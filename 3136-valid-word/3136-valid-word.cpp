class Solution {
public:
    bool isValid(string word) {
        if(word.size() < 3) return false;
        int vowelCount = 0;
        int consonantCount = 0;
        for(int i = 0;i < word.size();i++){
            if(word[i] == 'A' || word[i] == 'a' || word[i] == 'e' || word[i] == 'E' || word[i] == 'i' || word[i] == 'I' || word[i] == 'o' || word[i] == 'O' || word[i] == 'u' || word[i] == 'U') vowelCount++;
            else if((word[i] >= 'A' || word[i] >= 'a') && (word[i] <= 'Z' || word[i] <= 'z')) consonantCount++;
            else if(word[i] == '!' || word[i] == '@' || word[i] == '#' || word[i] == '$' || word[i] == '%') return false;
        }
        if(vowelCount >= 1 && consonantCount >= 1) return true;
        return false;
    }
};