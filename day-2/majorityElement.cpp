class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (auto i : nums)
            mp[i]++;
        int maxFreq = INT_MIN;
        int ans;
        for (auto i : mp)
        {
            if (i.second > maxFreq)
            {
                ans = i.first;
                maxFreq = i.second;
            }
        }

        return ans;
    }
};