class CustomStack {
public:
    int size;
    int capacity;
    stack<int> s1, s2;
    CustomStack(int maxSize)
    {
        size=0;
        capacity=maxSize;
    }

    void push(int x)
    {
        if(size==capacity)
            return;

        s1.push(x);

        size++;
    }

    int pop()
    {
        if(size==0)
            return -1;

        int ans=s1.top();
        s1.pop();

        size--;
        return ans;
    }

    void increment(int k, int val)
    {
        if(k>size)
        {
            while(!s1.empty())
            {
                s2.push((s1.top())+val);
                s1.pop();
            }

            while(!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }

            return;
        }

        for(int i=0; i<(size-k); i++)
        {
            s2.push(s1.top());
            s1.pop();
        }

        for(int i=0; i<k; i++)
        {
            s2.push((s1.top())+val);
            s1.pop();
        }

        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
