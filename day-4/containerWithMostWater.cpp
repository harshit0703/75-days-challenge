class Solution
{
public:
    int maxArea(vector<int> &height)
    {

        int n = height.size();
        int area = INT_MIN;

        int st = 0, en = n - 1;

        while (st < en)
        {
            int width = en - st;
            int currHeight = min(height[st], height[en]);
            area = max(area, width * currHeight);

            if (height[st] >= height[en])
                en--;

            else
                st++;
        }

        return area;
    }
};