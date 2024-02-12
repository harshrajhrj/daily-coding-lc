class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        int freq = 0;
        int i = 0, j = 0;
        while (j < n)
        {
            if (freq == 0)
                i = nums[j];
            if (nums[j] == i)
                freq++;
            else
                freq--;
            j++;
        }

        return i;
    }
};