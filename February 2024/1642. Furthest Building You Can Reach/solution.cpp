class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();

        priority_queue<int> pq;

        int result = 0;
        for (int i = 0; i < n - 1; i++) {
            int ascend = heights[i + 1] - heights[i];
            if (ascend <= 0) {
                result++;
                continue;
            }

            // assum we use bricks
            bricks -= ascend;
            pq.push(ascend);

            // if we can't use bricks, then we use ladder
            if (bricks < 0) {
                bricks += pq.top();
                pq.pop();

                // use ladder
                ladders--;
            }

            // if we can't use ladder too, then we arrived the destination
            if (ladders < 0)
                break;

            result++;
        }
        return result;
    }
};