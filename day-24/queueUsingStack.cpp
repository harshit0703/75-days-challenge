class MyQueue
{
public:
    stack<int> st1, st2;
    MyQueue()
    {
    }

    void push(int x)
    {
        st1.push(x);
    }

    int pop()
    {
        while (st1.size() > 1)
        {
            int n = st1.top();
            st1.pop();
            st2.push(n);
        }

        int ans = st1.top();
        st1.pop();

        while (!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }

        return ans;
    }

    int peek()
    {
        while (st1.size() > 1)
        {
            int n = st1.top();
            st1.pop();
            st2.push(n);
        }

        int ans = st1.top();
        st1.pop();
        st2.push(ans);
        while (!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
        return ans;
    }

    bool empty()
    {
        return st1.size() == 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */