class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid)
    {
        int rows=grid.size();
        int cols=grid.at(0).size();

        int ans=0;
        int fresh=0;
        int rotten=0;

        queue<pair<int, int>> q;

        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                if(grid.at(i).at(j)==1)
                {
                    fresh++;
                }
                else if(grid.at(i).at(j)==2)
                {
                    rotten++;
                    q.push(make_pair(i,j));
                }
            }
        }

        if(fresh==0)
            return 0;

        if(rotten==0)
            return -1;

        while(!q.empty())
        {
            ans++;

            int sz=q.size();
            for(int k=0; k<sz; k++)
            {
                pair<int, int> fr=q.front();
                q.pop();

                int i=fr.first, j=fr.second;

                if(i-1>=0 && grid.at(i-1).at(j)==1)
                {
                    fresh--;
                    grid.at(i-1).at(j)=2;

                    q.push(make_pair(i-1, j));
                }

                if(i+1<rows && grid.at(i+1).at(j)==1)
                {
                    fresh--;
                    grid.at(i+1).at(j)=2;

                    q.push(make_pair(i+1, j));
                }

                if(j-1>=0 && grid.at(i).at(j-1)==1)
                {
                    fresh--;
                    grid.at(i).at(j-1)=2;

                    q.push(make_pair(i, j-1));
                }

                if(j+1<cols && grid.at(i).at(j+1)==1)
                {
                    fresh--;
                    grid.at(i).at(j+1)=2;

                    q.push(make_pair(i, j+1));
                }
            }
        }

        if(fresh!=0)
            return -1;

        return ans-1;
    }
};
