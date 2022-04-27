class Solution
{
private:
    int atMost(vector<int> &nums, int k)
    {

        unordered_map<int, int> mp;
        int i = 0, j = 0;
        int ans = 0;
        int n = nums.size();

        while (j < n)
        {

            mp[nums[j]]++;

            if (mp.size() > k)
            {

                while (mp.size() > k)
                {

                    mp[nums[i]]--;
                    if (mp[nums[i]] == 0)
                    {
                        mp.erase(nums[i]);
                    }

                    i++;
                }
            }

            ans += j - i + 1; // why we are doing this??
            j++;
        }

        return ans;
    }

public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {

        // exactly k = atmost(k) - atmost(k-1)

        return atMost(nums, k) - atMost(nums, k - 1);
    }
};