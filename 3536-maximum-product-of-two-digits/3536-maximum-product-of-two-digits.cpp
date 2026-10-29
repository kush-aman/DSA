class Solution {
public:
    int maxProduct(int n) {
      vector<int> digi;
      while(n != 0){
        int remainder = n % 10;
        digi.push_back(remainder);
        n /= 10;
      }

      sort(digi.begin(),digi.end());
      return digi[digi.size() - 1] * digi[digi.size() - 2];
    }
};