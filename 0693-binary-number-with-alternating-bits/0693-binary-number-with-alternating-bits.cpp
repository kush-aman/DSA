class Solution {
public:
    bool hasAlternatingBits(int n) {
      vector<int> bits;
      while(n != 0){
        int remainder = n % 2;
        bits.push_back(remainder);
        n /= 2;
      }  
      for(int i = 0;i < bits.size() - 1;i++){
        if(bits[i] == bits[i+1]) return false;
      }
      return true;
    }
};