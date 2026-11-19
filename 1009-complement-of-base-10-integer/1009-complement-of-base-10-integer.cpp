class Solution {
public:
    int bitwiseComplement(int num) {
        if(num == 0) return 1;
        vector<int> bits;
        while(num != 0){
            int remainder = num % 2;
            bits.push_back(remainder);
            num /= 2;
        }
        vector<int> finalbits;
        for(int i = 0;i < bits.size();i++){
            int xorr = bits[i] ^ 1;
            finalbits.push_back(xorr);
        }
        int ans = 0;
        long long pow2 = 1;
        for(int i = 0;i < finalbits.size() ;i++){
            ans += finalbits[i] * pow2;
            pow2 *= 2;
        }
        return ans;
    }
};