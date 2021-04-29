class Solution {
public:
    int lastStoneWeight(vector<int>& stones)
    {
        if(stones.size()==1)
            return stones.at(0);

        priority_queue<int> pq(stones.begin(), stones.end());
        while(pq.size()>=2)
        {
            int y=pq.top();
            pq.pop();

            int x=pq.top();
            pq.pop();

            if(x!=y)
                pq.push(y-x);
        }

        if(!pq.empty())
            return pq.top();

        return 0;
    }
};
