class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0;
        int ans = 0;
        int len = bits.size();
        while(i < len){
            if(bits[i] == 1){
                 ans = i;
                 i += 2;
            }
            else{
                ans = i;
                i ++;
            }
        }
        if(bits[ans] == 0) return true;
        return false;
    }
};