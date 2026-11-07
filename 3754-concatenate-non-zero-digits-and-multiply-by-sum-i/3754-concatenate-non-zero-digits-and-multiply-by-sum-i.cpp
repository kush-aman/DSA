class Solution {
public:
    long long sumAndMultiply(int n) {
        vector<int> temp;
        long long x = 0;
        long long sum = 0;
        while(n != 0){
            int remainder = n % 10;
            if(remainder != 0){
                temp.push_back(remainder);
            } 
            n /= 10;
        }
        long long ans;
        for(int i = temp.size() - 1;i >= 0;i--){
            x = x * 10 + temp[i];
            sum += temp[i];
        }
        ans = x * sum;
        return ans;
    }
};