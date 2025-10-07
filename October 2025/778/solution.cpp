// 778. Swim in Rising Water
#include <bits/stdc++.h>
using namespace std;

int swimInWater(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    // simple pq based approach
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    vector<vector<int>> visited(m, vector<int>(n, 0));
    int row[] = {-1, 0, 1, 0};
    int col[] = {0, 1, 0, -1};

    pq.push({grid[0][0], 0, 0});
    visited[0][0] = 1;

    while (!pq.empty())
    {
        auto [time, i, j] = pq.top();
        pq.pop();

        if (i == m - 1 && j == n - 1)
            return time;

        for (int k = 0; k < 4; k++)
        {
            int newr = i + row[k];
            int newc = j + col[k];

            if (newr >= 0 && newr < m && newc >= 0 && newc < n && !visited[newr][newc])
            {
                visited[newr][newc] = 1;
                int max_time = max(time, grid[newr][newc]);
                pq.push({max_time, newr, newc});
            }
        }
    }

    return -1;
}