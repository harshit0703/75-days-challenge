class Solution
{
private:
    int solve(int n, vector<int> &prices, bool buy, vector<vector<int>> &dp)
    {
        if (n >= prices.size())
            return 0;

        if (dp[n][buy] != -1)
            return dp[n][buy];

        if (buy)
        {

            int leave = solve(n + 1, prices, buy, dp);
            int purchase = solve(n + 1, prices, !buy, dp) - prices[n];

            return dp[n][buy] = max(leave, purchase);
        }

        else
        {

            int leave = solve(n + 1, prices, buy, dp);
            int sell = solve(n + 1, prices, !buy, dp) + prices[n];

            return dp[n][buy] = max(leave, sell);
        }
    }

public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (n < 2)
            return 0;

        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        // we are making this to memoize it as we will se what happen if we buy or let it go

        // at first we have to but so we are sending buy = 1
        return solve(0, prices, 1, dp);
    }
};