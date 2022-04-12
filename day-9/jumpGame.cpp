class Solution
{
private:
    bool solve(vector<int> &nums, int index, vector<int> &dp)
    {

        if (index >= nums.size())
            return false;

        if (index == nums.size() - 1)
            return true;

        if (dp[index] != -1)
            return dp[index];

        int maxJump = nums[index];

        for (int i = 1; i <= maxJump; i++)
        {

            if (solve(nums, index + i, dp))
            {
                return dp[index] = true;
            }
        }

        return dp[index] = false;
    }

public:
    bool canJump(vector<int> &nums)
    {
        if (nums.size() == 1)
            return true;

        vector<int> dp(10001, -1);

        return solve(nums, 0, dp);
    }
};