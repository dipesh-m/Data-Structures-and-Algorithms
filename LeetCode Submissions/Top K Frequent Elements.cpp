//Bucket Sort Approach - O(n) time and O(n) space
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        unordered_map<int, int> um;
        for(auto z:nums)
            um[z]++;

        vector<int> ans;

        vector<vector<int>> bucket(nums.size()+1);
        for(auto z:um)
            bucket.at(z.second).push_back(z.first);

        for(int i=bucket.size()-1; i>=0; i--)
        {
            if(bucket.at(i).size()!=0)
            {
                for(int j=0; j<bucket.at(i).size(); j++)
                {
                    if(ans.size()==k)
                        break;

                    ans.push_back(bucket.at(i).at(j));
                }
            }

            if(ans.size()==k)
                break;
        }

        return ans;
    }
};

//QuickSelect Solution - O(n) average time and O(n^2) worst case time and O(n) space for map
class Solution {
public:
    int partition(vector<pair<int,int>>& vec, int lo, int hi, int pivot)
    {
        int i=lo, j=lo;
        while(j<=hi)
        {
            if(vec.at(j).second>=pivot)
            {
                swap(vec.at(i), vec.at(j));
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }

        return i-1;
    }

    int quickSelect(vector<pair<int,int>>& vec, int lo, int hi, int k, vector<int>& ans)
    {
        int pivot=vec[hi].second;
        int pi=partition(vec, lo, hi, pivot);

        if(k<pi)
        {
            return quickSelect(vec, lo, pi-1, k, ans);
        }
        else if(k>pi)
        {
            return quickSelect(vec, pi+1, hi, k, ans);
        }

        return pi;
    }

    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        unordered_map<int, int> um;
        for(auto z:nums)
            um[z]++;

        vector<int> ans;

        vector<pair<int,int>> vec;
        for(auto z:um)
            vec.push_back(make_pair(z.first, z.second));

        int pi=quickSelect(vec, 0, vec.size()-1, k-1, ans);

        for(int i=0; i<=pi; i++)
            ans.push_back(vec.at(i).first);

        return ans;
    }
};

//Heap Solution - O(nlogn) time and O(n) space

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        unordered_map<int, int> um;
        for(auto z:nums)
            um[z]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(auto it:um)
        {
            pq.emplace(make_pair(it.second, it.first));
            if(pq.size()>k)
                pq.pop();
        }

        vector<int> ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
