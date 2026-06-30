class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr;
        int i = 0;
        int j = 0;
        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] > nums2[j]){
                arr.push_back(nums2[j]);
                j++;
            }
            else{
                arr.push_back(nums1[i]);
                i++;
            }
        }
        while(i < nums1.size()){
            arr.push_back(nums1[i]);
            i++;
        }
        while(j < nums2.size()){
            arr.push_back(nums2[j]);
            j++;
        }

        int low = 0;
        int high = arr.size() - 1;
        int mid = (low + high) / 2;
        if(mid - low != high - mid){
            return (double)(arr[mid] + arr[mid+1])/2;
        }
        return arr[mid];
    }
};