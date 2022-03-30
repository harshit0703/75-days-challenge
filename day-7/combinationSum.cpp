class Solution
{
private:
    vector<vector<int>> res;
    void solve(vector<int> arr, int target, int n, vector<int> ans)
    {
        if (target == 0)
        {
            res.push_back(ans);
            return;
        }

        if (n == 0)
            return;

        if (arr[n - 1] > target)
        {
            solve(arr, target, n - 1, ans);
        }

        else
        {
            solve(arr, target, n - 1, ans);
            ans.push_back(arr[n - 1]);
            solve(arr, target - arr[n - 1], n, ans);
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        int n = candidates.size();
        solve(candidates, target, n, {});
        return res;
    }
};