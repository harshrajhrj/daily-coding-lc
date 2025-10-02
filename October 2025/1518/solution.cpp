// 1518. Water Bottles
#include <bits/stdc++.h>
using namespace std;

int numWaterBottles(int numBottles, int numExchange)
{
    return numBottles + (numBottles - 1) / (numExchange - 1);
}