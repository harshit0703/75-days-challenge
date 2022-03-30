class Solution
{
private:
    int solve(vector<int> &nums, int index, vector<int> &dp)
    {

        if (index >= nums.size() - 1)
            return 0;

        if (dp[index] != 10001)
            return dp[index];

        int maxJump = nums[index];

        for (int i = 1; i <= maxJump; i++)
        {

            dp[index] = min(dp[index], solve(nums, index + i, dp) + 1);
        }

        return dp[index];
    }

public:
    int jump(vector<int> &nums)
    {

        vector<int> dp(nums.size(), 10001);

        return solve(nums, 0, dp);
    }
};