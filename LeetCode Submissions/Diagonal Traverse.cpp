//SOLN 1
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat)
    {
        vector<int> ans;
        vector<deque<int>> vec;

        for(int i=0; i<mat.size(); i++)
        {
            for(int j=0; j<mat.at(0).size(); j++)
            {
                if(i+j<vec.size())
                {
                    if((i+j)%2!=0)
                        vec.at(i+j).push_back(mat[i][j]);
                    else
                        vec.at(i+j).push_front(mat[i][j]);
                }
                else
                {
                    deque<int> im;
                    im.push_back(mat[i][j]);

                    vec.push_back(im);
                }
            }
        }

        for(auto& z:vec)
        {
            for(auto& k:z)
                ans.push_back(k);
        }

        return ans;
    }
};

//SOLN 2
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat)
    {
        vector<int> ans;
        int i=0, j=0, rows=mat.size(), cols=mat.at(0).size(), c=0;
        while(i<rows && j<cols)
        {
            ans.push_back(mat[i][j]);

            if(c%2==0)
            {
                while(i-1>=0 && j+1<cols)
                {
                    i--;
                    j++;
                    ans.push_back(mat[i][j]);
                }

                if(j+1<cols)
                    j++;
                else
                    i++;

                c++;
            }
            else
            {
                while(i+1<rows && j-1>=0)
                {
                    i++;
                    j--;
                    ans.push_back(mat[i][j]);
                }

                if(i+1<rows)
                    i++;
                else
                    j++;

                c++;
            }
        }

        return ans;
    }
};
