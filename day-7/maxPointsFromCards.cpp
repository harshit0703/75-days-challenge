class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {

        int sum = 0;
        for (auto i : cardPoints)
            sum += i;
        int n = cardPoints.size();
        if (k == n)
            return sum;

        // you need to remove a subarray from this array such that the sum remains max of length = n - k

        int len = n - k;
        int ans = INT_MIN;
        int temp = 0;

        int i = 0;
        int j = 0;

        while (j < n)
        {
            temp += cardPoints[j];
            if (j - i + 1 == len)
            {
                ans = max(ans, sum - temp);
                temp -= cardPoints[i];
                i++;
            }
            j++;
        }

        return ans;
    }
};