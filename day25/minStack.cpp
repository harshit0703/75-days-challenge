class MinStack
{
public:
    stack<int> st;
    stack<int> minEle;

    MinStack()
    {
        // st.clear();
        // minEle.clear();
    }

    void push(int val)
    {
        st.push(val);
        if (minEle.empty())
            minEle.push(val);
        else if (val <= minEle.top())
            minEle.push(val);
    }

    void pop()
    {
        if (st.top() == minEle.top())
            minEle.pop();
        st.pop();
    }

    int top()
    {
        return st.top();
    }

    int getMin()
    {
        return minEle.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */