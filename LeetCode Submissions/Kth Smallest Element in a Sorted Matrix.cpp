//m=no.of rows, n=no. of columns
// HEAP SOLN.- O(mnlogk) time and O(k) space
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k)
    {
        priority_queue<int> pq;
        for(auto z:matrix)
        {
            for(auto y:z)
            {
                pq.push(y);

                if(pq.size()>k)
                    pq.pop();
            }
        }

        return pq.top();
    }
};
