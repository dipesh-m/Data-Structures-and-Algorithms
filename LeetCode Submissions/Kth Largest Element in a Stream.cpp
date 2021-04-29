class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int maxNeeded;
public:
    KthLargest(int k, vector<int>& nums)
    {
        maxNeeded=k;
        for(auto z:nums)
        {
            pq.push(z);
            if(pq.size()>maxNeeded)
                pq.pop();
        }
    }

    int add(int val)
    {
        pq.push(val);

        if(pq.size()>maxNeeded)
            pq.pop();

        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
