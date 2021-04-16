class Solution {
public:
    int getKth(int lo, int hi, int k)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        while(lo<=hi)
        {
            int x=lo, count=0;
            while(x!=1)
            {
                if(x%2==0)
                {
                    x/=2;
                }
                else
                {
                    x=(3*x)+1;
                }

                count++;
            }

            pq.push(make_pair(count, lo));
            lo++;
        }

        k--;
        while(k-->0)
        {
            pq.pop();
        }

        return pq.top().second;
    }
};
