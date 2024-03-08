class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;

        int maxi = INT_MIN;
        for (auto v : nums) {
            freq[v]++;
            // find maxi
            if (freq[v] > maxi)
                maxi = freq[v];
        }

        int total = 0;

        for (auto [key, value] : freq) {
            // add value that equals maxi
            if (value == maxi) {
                total += value;
            }
        }

        return total;
    }
};