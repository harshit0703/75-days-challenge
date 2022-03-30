class Solution
{
public:
    int numPairsDivisibleBy60(vector<int> &time)
    {
        int ans = 0;
        unordered_map<int, int> mp;

        for (auto i : time)
        {
            int rem = i % 60;
            if (rem == 0)
            {
                ans += mp[0];
            }

            else
                ans += mp[60 - rem];

            mp[rem]++;
        }

        return ans;
    }
};