class Solution
{

public:
    vector<int> help_classmate(vector<int> arr, int n)
    {
        // we just need to calculate the nearest smaller to right
        stack<int> st;
        vector<int> ans;

        for (int i = n - 1; i >= 0; i--)
        {
            if (st.empty())
            {
                ans.push_back(-1);
            }
            else
            {
                while (!st.empty() && st.top() >= arr[i])
                    st.pop();
                if (st.empty())
                    ans.push_back(-1);
                else
                    ans.push_back(st.top());
            }

            st.push(arr[i]);
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};