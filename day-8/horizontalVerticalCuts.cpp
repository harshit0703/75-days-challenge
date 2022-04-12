class Solution
{
private:
    int MOD = 1e9 + 7;

public:
    int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts)
    {
        // the biggest piece of the cake will be formed by the thickest cut both vertically and horizontally

        int hs = horizontalCuts.size();
        int vs = verticalCuts.size();

        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());

        long int maxHeight = horizontalCuts[0]; // first cut height
        long int maxLength = verticalCuts[0];   // first cut length

        for (int i = 1; i < hs; i++)
        {
            maxHeight = max(maxHeight, (long int)horizontalCuts[i] - horizontalCuts[i - 1]);
        }

        maxHeight = max(maxHeight, (long int)h - horizontalCuts[hs - 1]);

        for (int i = 1; i < vs; i++)
        {
            maxLength = max(maxLength, (long int)verticalCuts[i] - verticalCuts[i - 1]);
        }

        maxLength = max(maxLength, (long int)w - verticalCuts[vs - 1]);

        cout << maxHeight << maxLength << endl;

        return (maxHeight * maxLength) % MOD;
    }
};