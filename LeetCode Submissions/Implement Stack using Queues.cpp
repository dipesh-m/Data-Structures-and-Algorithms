//USING 1 QUEUE
class MyStack {
private:
    queue<int> q;
public:
    /** Initialize your data structure here. */
    MyStack() {}

    /** Push element x onto stack. */
    void push(int x)
    {
        q.push(x);

        int sz=q.size();
        while(sz!=1)
        {
            q.push(q.front());
            q.pop();

            sz--;
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        int ans=q.front();
        q.pop();
        return ans;
    }

    /** Get the top element. */
    int top()
    {
        return q.front();
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return q.empty();
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

//USING 2 QUEUES and ONE INTEGER VARIABLE

class MyStack {
private:
    queue<int> q1,q2;
    int t;
public:
    /** Initialize your data structure here. */
    MyStack() {}

    /** Push element x onto stack. */
    void push(int x)
    {
        q1.push(x);
        t=x;
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        int ans;
        while(!q1.empty())
        {
            if(q1.size()==1)
                ans=q1.front();
            else
            {
                if(q1.size()==2)
                    t=q1.front();

                q2.push(q1.front());
            }

            q1.pop();
        }

        q1.swap(q2);
        return ans;
    }

    /** Get the top element. */
    int top()
    {
        return t;
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return q1.empty();
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
