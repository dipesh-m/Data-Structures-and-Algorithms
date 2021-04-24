class FreqStack
{
private:
    unordered_map<int, int> um;
    map<int, vector<int>, greater<int>> m;
public:

    FreqStack() {}

    void push(int val)
    {
        um[val]++;

        if(m.count(um.at(val))>0)
        {
            m[um.at(val)].push_back(val);
        }
        else
        {
            vector<int> im;
            im.push_back(val);

            m[um.at(val)]=im;
        }
    }

    int pop()
    {
        auto it=m.begin();
        int ans=it->second.at(it->second.size()-1);

        it->second.pop_back();
        if(it->second.size()==0)
            m.erase(it);

        um.at(ans)--;

        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
