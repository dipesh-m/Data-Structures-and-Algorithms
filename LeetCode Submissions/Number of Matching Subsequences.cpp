class Solution {
public:
    bool checkSub(string& x, vector<vector<int>>& um)
    {
        int prev=-1;
        for(int i=0; i<x.size(); i++)
        {
            if(um.at(x[i]-'a').size()==0)
                return false;

            vector<int>& vec=um.at(x[i]-'a');

            int lo=0, hi=vec.size()-1, mid;
            while(lo<=hi)
            {
                mid=lo+(hi-lo)/2;

                if((mid==0 || vec[mid-1]<=prev) && vec[mid]>prev)
                {
                    prev=vec[mid];
                    break;
                }
                else if(prev>=vec[mid])
                    lo=mid+1;
                else
                    hi=mid-1;
            }

            if(lo>hi)
                return false;
        }

        return true;
    }

    int numMatchingSubseq(string s, vector<string>& words)
    {
        vector<vector<int>> um(26);
        for(int i=0; i<s.size(); i++)
            um[s[i]-'a'].push_back(i);

        int ans=0;
        for(auto& z:words)
        {
            if(checkSub(z, um))
                ans++;
        }

        return ans;
    }
};
