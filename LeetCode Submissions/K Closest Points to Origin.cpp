//QUICK SELECT SOLN
class Solution {
public:
    int partition(vector<pair<double, vector<int>>>& vec, int lo, int hi, double pivot)
    {
        int i=lo, j=lo;
        while(j<=hi)
        {
            if(vec[j].first<=pivot)
            {
                swap(vec[i], vec[j]);
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

    int quickSelect(vector<pair<double, vector<int>>>& vec, int lo, int hi, int k)
    {
        double pivot=vec[hi].first;
        int pi=partition(vec, lo, hi, pivot);

        if(k<pi)
            return quickSelect(vec, lo, pi-1, k);
        else if(k>pi)
            return quickSelect(vec, pi+1, hi, k);

        return pi;
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
    {
        vector<vector<int>> ans;

        vector<pair<double, vector<int>>> vec;
        for(auto z:points)
            vec.push_back(make_pair(sqrt((z.at(0)*z.at(0))+(z.at(1)*z.at(1))), z));

        int pi=quickSelect(vec, 0, vec.size()-1, k-1);
        for(int i=0; i<=pi; i++)
            ans.push_back(vec.at(i).second);

        return ans;
    }
};

//HEAP SOLN
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
    {
        vector<vector<int>> ans;

        priority_queue<pair<double, vector<int>>> pq;
        for(auto z:points)
        {
            pq.push(make_pair(sqrt((z.at(0)*z.at(0))+(z.at(1)*z.at(1))), z));

            if(pq.size()>k)
                pq.pop();
        }

        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
