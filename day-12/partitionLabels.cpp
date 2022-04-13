class Solution
{
public:
    vector<int> partitionLabels(string s)
    {

        vector<int> v(26, 0);
        for (auto i : s)
        {
            v[i - 'a']++;
        }

        int cnt = 0;
        vector<int> ans;
        unordered_set<char> st;

        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            cnt++;
            v[s[i] - 'a']--;
            st.insert(s[i]);

            if (v[s[i] - 'a'] == 0)
            {
                int flag = 0;
                for (auto i : st)
                {
                    if (v[i - 'a'] != 0)
                    {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0)
                {
                    // we can make a partition here
                    ans.push_back(cnt);
                    st.clear();
                    cnt = 0;
                }
            }
        }

        return ans;
    }
};