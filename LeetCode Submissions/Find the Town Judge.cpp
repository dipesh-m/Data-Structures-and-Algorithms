class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust)
    {
        vector<int> deg(N+1, 0);

        for(auto z:trust)
        {
            deg.at(z.at(0))++;
            deg.at(z.at(1))--;
        }

        for(int i=1; i<N+1; i++)
        {
            if(deg.at(i)==-(N-1))
                return i;
        }

        return -1;
    }
};
