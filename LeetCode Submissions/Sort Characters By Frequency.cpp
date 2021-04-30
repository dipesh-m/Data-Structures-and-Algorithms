//BUCKET SORT SOLUTION - O(n) time and O(n) space
class Solution {
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> um;
        for(auto z:s)
            um[z]++;

        string ans;

        vector<vector<char>> bucket(s.size()+1);
        for(auto z:um)
            bucket.at(z.second).push_back(z.first);

        for(int i=bucket.size()-1; i>=0; i--)
        {
            if(bucket.at(i).size()!=0)
            {
                for(auto k:bucket.at(i))
                {
                    for(int i=0; i<um.at(k); i++)
                    {
                        ans+=k;
                    }
                }
            }
        }

        return ans;
    }
};

//HEAP SOLUTION - O(nlogn) time and O(n) space

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
