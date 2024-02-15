class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        priority_queue<int> keepLongestSide;
        long long sum = 0;

        for (auto v : nums) {
            keepLongestSide.push(v);
            sum += v;
        }

        while (!keepLongestSide.empty()) {
            int longestSide = keepLongestSide.top();
            long long sumOfOtherSides = sum - longestSide;
            if (longestSide < sumOfOtherSides) {
                return sum;
            } else {
                sum -= longestSide;
                keepLongestSide.pop();
            }
        }

        return -1;
    }
};