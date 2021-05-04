class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat)
    {
        int ans=0, i=0, j=0, rows=mat.size(), cols=mat.at(0).size();

        while(i<rows && j<cols)
        {
            ans+=mat[i][j];
            i++;
            j++;
        }

        i=0, j=cols-1;
        while(i<rows && j>=0)
        {
            ans+=mat[i][j];
            i++;
            j--;
        }

        return rows%2==0 ? ans : ans-mat[rows/2][cols/2];
    }
};
