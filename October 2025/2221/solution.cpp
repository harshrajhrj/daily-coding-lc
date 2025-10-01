// 2221. Find triangular sum of an array
#include <bits/stdc++.h>
using namespace std;

int triangularSum(vector<int> &nums)
{
    if (nums.size() == 1)
        return nums[0];

    queue<pair<int, int>> q;
    for (int i = 1; i < nums.size(); i++)
    {
        q.push({nums[i - 1], nums[i]});
    }
    while (q.size() != 1)
    {
        int n = q.size();
        for (int i = 0; i < n - 1; i++)
        {
            pair<int, int> prev = q.front();
            q.pop();
            int prevVal = (prev.first + prev.second) % 10;

            pair<int, int> curr = q.front();
            int currVal = (curr.first + curr.second) % 10;
            q.push({prevVal, currVal});
        }
        q.pop();
    }

    int first = q.front().first;
    int second = q.front().second;

    q.pop();

    return (first + second) % 10;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << triangularSum(nums);
    return 0;
}