class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum)
    {
        vector<vector<int>> mat(rowSum.size(), vector<int>(colSum.size()));
        for(int i=0; i<rowSum.size(); i++)
        {
            for(int j=0; j<colSum.size(); j++)
            {
                mat.at(i).at(j)=min(rowSum.at(i), colSum.at(j));
                rowSum.at(i)-=mat.at(i).at(j);
                colSum.at(j)-=mat.at(i).at(j);
            }
        }

        return mat;
    }
};
