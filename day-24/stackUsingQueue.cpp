class MyStack
{
public:
    queue<int> q1, q2;

    MyStack()
    {
    }

    void push(int x)
    {
        q1.push(x);
    }

    int pop()
    {
        while (q1.size() > 1)
        {
            int n = q1.front();
            q1.pop();
            q2.push(n);
        }

        int ans = q1.front();
        q1.pop();

        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;

        return ans;
    }

    int top()
    {
        while (q1.size() > 1)
        {
            int n = q1.front();
            q1.pop();
            q2.push(n);
        }

        int ans = q1.front();
        q1.pop();
        q2.push(ans);

        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;

        return ans;
    }

    bool empty()
    {
        return q1.size() == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */