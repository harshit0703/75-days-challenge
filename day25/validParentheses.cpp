class Solution
{
public:
    bool isValid(string s)
    {

        if (s.length() % 2 == 1)
            return false;

        stack<char> st;

        for (int i = 0; i < s.length(); i++)
        {

            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);
            else
            {
                if (st.size() == 0 || s[i] == ')' && st.top() != '(' || s[i] == '}' && st.top() != '{' || s[i] == ']' && st.top() != '[')
                    return false;
                st.pop();
            }
        }

        return (st.size() == 0);
    }
};