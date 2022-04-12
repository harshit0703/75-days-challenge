class Solution
{
    void solve(vector<int> &nums, vector<int> ans, int n, vector<vector<int>> &res)
    {

        if (n == nums.size())
        {
            res.push_back(ans);
            return;
        }

        // we have two choices either to include this in the vector or not
        solve(nums, ans, n + 1, res);

        int temp = nums[n];
        ans.push_back(temp);

        solve(nums, ans, n + 1, res);
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> res;
        solve(nums, {}, 0, res);
        return res;
    }
};