class Solution
{

private:
    void findNsl(vector<int> &nsl, vector<int> &heights)
    {
        stack<pair<int, int>> st;
        int n = heights.size();

        for (int i = 0; i < n; i++)
        {
            if (st.empty())
            {
                nsl.push_back(-1);
            }
            else
            {
                while (!st.empty() && st.top().second >= heights[i])
                    st.pop();
                if (st.empty())
                    nsl.push_back(-1);
                else
                    nsl.push_back(st.top().first);
            }

            st.push({i, heights[i]});
        }
    }

    void findNsr(vector<int> &nsr, vector<int> &heights)
    {
        stack<pair<int, int>> st;
        int n = heights.size();

        for (int i = n - 1; i >= 0; i--)
        {
            if (st.empty())
            {
                nsr.push_back(n);
            }
            else
            {
                while (!st.empty() && st.top().second >= heights[i])
                    st.pop();
                if (st.empty())
                    nsr.push_back(n);
                else
                    nsr.push_back(st.top().first);
            }

            st.push({i, heights[i]});
        }

        reverse(nsr.begin(), nsr.end());
    }

public:
    int largestRectangleArea(vector<int> &heights)
    {
        vector<int> nsl, nsr;
        findNsl(nsl, heights);
        findNsr(nsr, heights);

        int n = heights.size();
        vector<int> width(n);

        for (int i = 0; i < n; i++)
        {
            width[i] = nsr[i] - nsl[i] - 1;
        }

        int ans = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            int area = heights[i] * width[i];
            ans = max(ans, area);
        }

        return ans;
    }
};