//SOLN 1
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat)
    {
        int rows=mat.size(), cols=mat.at(0).size();
        vector<int> ans(rows*cols);

        unordered_map<int, vector<int>> um;
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
                um[i+j].push_back(mat[i][j]);
        }

        int k=0;
        for(int i=0, j=0; j<cols; j++)
        {
            if((i+j)%2==0)
            {
                for(int l=um[i+j].size()-1; l>=0; l--)
                    ans[k++]=um[i+j].at(l);
            }
            else
            {
                for(int l=0; l<um[i+j].size(); l++)
                    ans[k++]=um[i+j].at(l);
            }
        }

        for(int j=cols-1, i=1; i<rows; i++)
        {
            if((i+j)%2==0)
            {
                for(int l=um[i+j].size()-1; l>=0; l--)
                    ans[k++]=um[i+j].at(l);
            }
            else
            {
                for(int l=0; l<um[i+j].size(); l++)
                    ans[k++]=um[i+j].at(l);
            }
        }

        return ans;
    }
};

//SOLN 2
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat)
    {
        int i=0, j=0, rows=mat.size(), cols=mat.at(0).size(), k=0;
        bool even=true;
        vector<int> ans(rows*cols);

        while(i<rows && j<cols)
        {
            ans[k++]=mat[i][j];

            if(even)
            {
                while(i-1>=0 && j+1<cols)
                {
                    i--;
                    j++;
                    ans[k++]=mat[i][j];
                }

                if(j+1<cols)
                    j++;
                else
                    i++;

                even=false;
            }
            else
            {
                while(i+1<rows && j-1>=0)
                {
                    i++;
                    j--;
                    ans[k++]=mat[i][j];
                }

                if(i+1<rows)
                    i++;
                else
                    j++;

                even=true;
            }
        }

        return ans;
    }
};
