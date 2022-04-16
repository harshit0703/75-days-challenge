class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {

        vector<int> ngr;
        stack<int> st;

        for (int i = nums2.size() - 1; i >= 0; i--)
        {

            if (st.empty())
            {
                ngr.push_back(-1);
            }

            else
            {
                while (!st.empty() && st.top() < nums2[i])
                    st.pop();
                if (st.empty())
                    ngr.push_back(-1);
                else
                    ngr.push_back(st.top());
            }

            st.push(nums2[i]);
        }

        reverse(ngr.begin(), ngr.end());

        unordered_map<int, int> mp;
        for (int i = 0; i < nums2.size(); i++)
        {
            mp[nums2[i]] = ngr[i];
        }

        vector<int> ans;

        for (auto i : nums1)
        {
            ans.push_back(mp[i]);
        }

        return ans;
    }
};