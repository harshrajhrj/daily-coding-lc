class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        // keep freq
        unordered_map<int, int> freq;
        for(auto v : arr) {
            freq[v]++;
        }

        // keep least freq on top
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > mini;
        for(auto [index, val] : freq) {
            mini.push(make_pair(val, index));
        }

        // start poping least freq
        while(!mini.empty()) {
            if(k - mini.top().first >= 0) {
                k -= mini.top().first;
                mini.pop();
            } else
                break;
        }
        return mini.size();
    }
};