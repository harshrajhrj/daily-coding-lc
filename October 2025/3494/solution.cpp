// 3494. Find the Minimum Amount of Time to Brew Potions
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
class Solution
{
public:
    long long minTime(vector<int> &skill, vector<int> &mana)
    {
        int n = skill.size();
        int m = mana.size();

        // simulate

        vector<ll> ps(n + 1, 0);
        for (int i = 0; i < m; i++) // potion
        {
            // 1 mana
            // 1 5 2 4 skill
            for (int j = 0; j < n; j++) // skill
            {
                ps[j + 1] = max(ps[j + 1], ps[j]) + 1LL * mana[i] * skill[j];
            }

            for (int j = 0; j <= n; j++)
            {
                cout << ps[j] << " ";
            }

            cout << endl;

            for (int j = n - 1; j > 0; j--)
            {
                ps[j] = ps[j + 1] - 1LL * mana[i] * skill[j];
            }

            for (int j = 0; j <= n; j++)
            {
                cout << ps[j] << " ";
            }

            cout << endl;
            cout << endl;
        }
        return ps[n];
    }
};