class Solution {
public:
    int hammingWeight(int n) {
        vector<int> bits;
        while(n!=0){
            int remainder = n % 2;
            bits.push_back(remainder);
            n /= 2;
        }
        int count = 0;
        for(int i = 0;i < bits.size();i++){
            if(bits[i] == 1) count++;
        }
        return count;
    }
};