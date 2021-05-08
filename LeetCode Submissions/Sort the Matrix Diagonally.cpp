class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat)
    {
        int rows=mat.size(), cols=mat.at(0).size(), i=0, j=cols-1, x, y;
        priority_queue<int, vector<int>, greater<int>> pq;

        while(i<rows)
        {
            x=i, y=j;
            while(x<rows && y<cols)
            {
                pq.push(mat[x][y]);
                x++;
                y++;
            }

            x=i, y=j;
            while(x<rows && y<cols)
            {
                mat[x][y]=pq.top();
                pq.pop();
                x++;
                y++;
            }

            if(j==0)
                i++;
            else
                j--;
        }

        return mat;
    }
};
