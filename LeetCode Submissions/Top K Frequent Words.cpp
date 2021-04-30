// Bucket Sort Solution - O(n + klogk) time and O(n) space
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k)
    {
        unordered_map<string, int> um;
        for(auto z:words)
            um[z]++;

        vector<string> ans;

        vector<vector<string>> bucket(words.size()+1);
        for(auto z:um)
            bucket.at(z.second).push_back(z.first);

        for(int i=bucket.size()-1; i>=0; i--)
        {
            if(bucket.at(i).size()!=0)
            {
                sort(bucket.at(i).begin(), bucket.at(i).end());
                for(auto z:bucket.at(i))
                {
                    if(ans.size()==k)
                        break;

                    ans.push_back(z);
                }
            }

            if(ans.size()==k)
                break;
        }

        return ans;
    }
};


//Heap Solution - O(nlogk) time and O(n) space for map
struct comp
{
    bool operator()(const pair<int, string>& a, const pair<int, string>& b) const
    {
        if(a.first==b.first)
        {
            return a.second<b.second;
        }

        return a.first>b.first;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k)
    {
        unordered_map<string, int> um;
        for(auto z:words)
        {
            um[z]++;
        }

        priority_queue<pair<int, string>, vector<pair<int, string>>, comp> pq;
        for(auto it:um)
        {
            pq.emplace(make_pair(it.second, it.first));
            if(pq.size()>k)
                pq.pop();
        }

        vector<string> ans(pq.size());
        int i=ans.size()-1;
        while(!pq.empty())
        {
            ans.at(i)=pq.top().second;
            pq.pop();
            i--;
        }

        return ans;
    }
};
