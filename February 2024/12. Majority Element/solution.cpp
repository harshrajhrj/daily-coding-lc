class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        int freq = 0;
        int major = 0, j = 0;
        while (j < n)
        {
            if (freq == 0)
                major = nums[j];
            if (nums[j] == major)
                freq++;
            else
                freq--;
            j++;
        }

        return major;
    }
};