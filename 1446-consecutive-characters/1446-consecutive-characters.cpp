class Solution {
public:
    int maxPower(string s) {
        int maxi = INT_MIN;
        int el = s[0];
        int count = 0;
        for(auto c : s){
            if(c == el){
                count++;
                maxi = max(count,maxi);
            }
            else{
                el = c;
                count = 1; 
            }
        }
        return maxi;
    }
};