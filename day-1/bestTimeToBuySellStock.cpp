class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> arr(n); // simply create an array for the max on the right
        arr[n - 1] = prices[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            if (prices[i] > arr[i + 1])
            {
                arr[i] = prices[i];
            }
            else
            {
                arr[i] = arr[i + 1];
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, arr[i] - prices[i]);
        }

        return ans;
    }
};