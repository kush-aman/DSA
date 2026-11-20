class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int left = 0,right = arr.size() - 1;
        while(left + 1 < arr.size() - 1 && arr[left] < arr[left+1]) left++;
        while(right > 0 && arr[right] < arr[right - 1]) right--;
        return left < arr.size() && left == right && right > 0;
    }
};