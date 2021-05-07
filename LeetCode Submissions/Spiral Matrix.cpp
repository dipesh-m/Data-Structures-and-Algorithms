class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat)
    {
        vector<int> ans;

        int rowBegin=0, rowEnd=mat.size()-1, colBegin=0, colEnd=mat.at(0).size()-1, ele=mat.size()*mat.at(0).size();
        while(ans.size()<ele)
        {
            for(int i=colBegin; i<=colEnd && ans.size()<ele; i++)
                ans.push_back(mat[rowBegin][i]);

            for(int i=rowBegin+1; i<=rowEnd && ans.size()<ele; i++)
                ans.push_back(mat[i][colEnd]);

            for(int i=colEnd-1; i>=colBegin && ans.size()<ele; i--)
                ans.push_back(mat[rowEnd][i]);

            for(int i=rowEnd-1; i>=rowBegin+1 && ans.size()<ele; i--)
                ans.push_back(mat[i][colBegin]);

            rowBegin++;
            colBegin++;
            rowEnd--;
            colEnd--;
        }

        return ans;
    }
};
