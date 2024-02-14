class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int positive = 0, negative = 1;
        vector<int> result(nums.size());

        for (auto v : nums) {
            if (v > 0) {
                result[positive] = v;
                positive += 2;
            } else {
                result[negative] = v;
                negative += 2;
            }
        }

        return result;
    }
};