class Solution {
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> um;
        for(auto z:s)
            um[z]++;

        priority_queue<pair<int, char>> pq;
        for(auto it:um)
        {
            pq.push(make_pair(it.second, it.first));
        }

        string ans;
        while(!pq.empty())
        {
            int currSize=pq.top().first;
            while(currSize--)
            {
                ans+=pq.top().second;
            }
            pq.pop();
        }

        return ans;
    }
};
