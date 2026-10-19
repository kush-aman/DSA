class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
       vector<int> ans;
       for(int i = 0;i < nums1.size();i++){
            int flag = 0;
            int ind = 0;
            while(nums1[i] != nums2[ind]) ind++;
            for(int j = ind;j < nums2.size();j++){
                if(nums2[j] > nums1[i]){
                    ans.push_back(nums2[j]);
                    flag = 1;
                    break;
                }
            }

        if(flag == 0) ans.push_back(-1);
       }
       return ans;
    }
};