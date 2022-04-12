class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        int n = nums.size();
        int i = 0;
        int sum = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        int ans = 0;

        while (i < n)
        {
            sum += nums[i];
            int rem = sum % k;
            if (rem < 0)
                rem += k;
            ans += mp[rem];
            mp[rem]++;
            i++;
        }

        return ans;
    }
};