class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int pro = 1;
        int num = n;

        while(num > 0){
            int remainder = num % 10;
            sum += remainder;
            pro *= remainder;
            num /= 10;
        }
        int total = sum + pro;
        if(n % total == 0) return true;
        return false;
    }
};