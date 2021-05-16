class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime)
    {
        vector<vector<int>> vec(n);
        for(int i=0; i<manager.size(); i++)
        {
            if(manager[i]!=-1)
                vec.at(manager[i]).push_back(i);
        }

        int ans=0;
        queue<pair<int,int>> q;
        q.push(make_pair(headID,0));

        while(!q.empty())
        {
            int sz=q.size();
            for(int i=0; i<sz; i++)
            {
                pair<int,int> fr=q.front();
                q.pop();

                ans=max(ans, fr.second);

                for(int j=0; j<vec.at(fr.first).size(); j++)
                    q.push(make_pair(vec.at(fr.first).at(j), fr.second+informTime[fr.first]));
            }
        }

        return ans;
    }
};
