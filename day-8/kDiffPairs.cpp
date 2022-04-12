class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {

        int n = nums.size();
        sort(nums.begin(), nums.end());
        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int diff = abs(nums[i] - nums[j]);
                if (diff == k)
                {
                    cnt++;
                    break;
                }
                while (j < n - 1 && nums[j + 1] == nums[j]) // removing duplicates
                    j++;
            }
            while (i < n - 1 && nums[i] == nums[i + 1]) // removing duplicates
                i++;
        }

        return cnt;
    }
};