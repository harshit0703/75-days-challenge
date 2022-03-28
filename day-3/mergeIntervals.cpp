class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.size() == 1)
            return intervals;
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        for (int i = 0; i < intervals.size(); i++)
        {
            int st = intervals[i][0];
            int en = intervals[i][1];

            int j = i + 1;
            while (j < intervals.size() && intervals[j][0] <= en)
            {
                en = max(en, intervals[j][1]);
                j++;
            }

            if (j != i + 1)
                i = j - 1;

            ans.push_back({st, en});
        }

        return ans;
    }
};