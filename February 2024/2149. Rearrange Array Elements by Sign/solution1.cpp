class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        queue<int> positive;
        queue<int> negative;
        vector<int> result;
        for (auto v : nums) {
            if (v > 0)
                positive.push(v);
            else
                negative.push(v);
        }

        while (!positive.empty()) {
            result.push_back(positive.front());
            result.push_back(negative.front());
            positive.pop();
            negative.pop();
        }

        return result;
    }
};