class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        for(auto v : nums1) {
            if(binary_search(nums2.begin(), nums2.end(), v))
                return v;
        }

        return -1;
    }
};