class Solution {
public:
#define pr pair<int, int>
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<pr> adjList[n];

        // graph is bidirectional
        for (auto v : meetings) {
            adjList[v[0]].push_back({v[1], v[2]});
            adjList[v[1]].push_back({v[0], v[2]});
        }

        vector<bool> hasSecret(n, false);
        priority_queue<pr, vector<pr>, greater<pr>> pq;

        // at time 0, person "0" knows the secret
        pq.push({0, 0});

        // at time 0, person "firstPerson" also knows the secret
        pq.push({0, firstPerson});

        while (!pq.empty()) {
            auto item = pq.top();
            int time = item.first;
            int person = item.second;
            pq.pop();

            if (hasSecret[person])
                continue;

            hasSecret[person] = true;

            for (auto v : adjList[person]) {
                if (!hasSecret[v.first] && v.second >= time) {
                    pq.push({v.second, v.first});
                }
            }
        }

        vector<int> sharedSecrets;
        for (int i = 0; i < n; i++) {
            if (hasSecret[i])
                sharedSecrets.push_back(i);
        }

        return sharedSecrets;
    }
};