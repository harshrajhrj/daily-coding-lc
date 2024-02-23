class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adjList[n];
        for(auto v : flights)
            adjList[v[0]].push_back({v[1], v[2]});

        // {stop, {dist, cost}}
        queue<pair<int, pair<int, int>>> minStop;
        minStop.push({0, {src, 0}}); // initially at src node
        
        vector<int> dist(n, 1e9); // initialize dist[]
        dist[src] = 0; // we know

        // using priority queue (E logV)
        // without priority queue (E = elements in flights), only loop number of times the edges are in the queue
        while(!minStop.empty()) {
            auto pickMinStop = minStop.front();
            minStop.pop();

            int stops = pickMinStop.first;
            int node = pickMinStop.second.first;
            int cost = pickMinStop.second.second;

            if(stops > k) continue; // no need to explore if stops exceeds "k"

            for(auto v : adjList[node]) {
                int neighbour = v.first;
                int costToNeighbour = v.second;

                if(cost + costToNeighbour < dist[neighbour]) {
                    dist[neighbour] = cost + costToNeighbour;
                    minStop.push({stops + 1, {neighbour, cost + costToNeighbour}});
                }
            }
        }

        if(dist[dst] == 1e9) return -1; // no route
        return dist[dst];
    }
};