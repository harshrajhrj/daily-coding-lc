// 3100. Water Bottles II
#include <bits/stdc++.h>
using namespace std;

int maxBottlesDrunk(int numBottles, int numExchange)
{
    int ans = 0;
    while (numBottles >= numExchange)
    {
        numBottles -= numExchange;
        ans += numExchange;
        numExchange++;
        numBottles++;
    }
    // return the remaining bottles that has been + supposed to be drunk
    return ans + numBottles;
}