class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries)
    {
        int ans=0, i=0;
        for(; i<A.size(); i++)
        {
            if(A[i]%2==0)
                ans+=A[i];
        }

        vector<int> res(queries.size());
        i=0;
        for(auto& z: queries)
        {
            if(A[z[1]]%2==0)
                ans-=A[z[1]];

            A[z[1]]+=z[0];

            if(A[z[1]]%2==0)
                ans+=A[z[1]];

            res[i]=ans;
            i++;
        }

        return res;
    }
};
