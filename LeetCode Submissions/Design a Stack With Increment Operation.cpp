class CustomStack {
private:
    vector<int>* st;
    int nextIndex=0;
public:
    CustomStack(int maxSize)
    {
        st=new vector<int>(maxSize);
    }

    void push(int x)
    {
        if(nextIndex==st->size())
            return;

        st->at(nextIndex)=x;
        nextIndex++;
    }

    int pop()
    {
        if(nextIndex==0)
            return -1;

        nextIndex--;
        return st->at(nextIndex);
    }

    void increment(int k, int val)
    {
        if(st->size()<=k)
            k=st->size();

        for(int i=0; i<k; i++)
            st->at(i)+=val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
