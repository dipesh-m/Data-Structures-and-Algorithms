class Solution {
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> mat(n, vector<int>(n));

        int rowBegin=0, rowEnd=n-1, colBegin=0, colEnd=n-1, k=1;
        while(k<=n*n)
        {
            for(int i=colBegin; i<=colEnd && k<=n*n; i++, k++)
                mat[rowBegin][i]=k;

            for(int i=rowBegin+1; i<=rowEnd && k<=n*n; i++, k++)
                mat[i][colEnd]=k;

            for(int i=colEnd-1; i>=colBegin && k<=n*n; i--, k++)
                mat[rowEnd][i]=k;

            for(int i=rowEnd-1; i>=rowBegin+1 && k<=n*n; i--, k++)
                mat[i][colBegin]=k;


            rowBegin++;
            colBegin++;
            rowEnd--;
            colEnd--;
        }

        return mat;
    }
};
