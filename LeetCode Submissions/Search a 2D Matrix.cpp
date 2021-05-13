//O(log(m)+log(n)) or O(log(mn))
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int& target)
    {
        int lo=0, n=matrix.at(0).size(), hi=(matrix.size()*n)-1;
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            if(target==matrix[mid/n][mid%n])
                return true;
            else if(target>matrix[mid/n][mid%n])
                lo=mid+1;
            else
                hi=mid-1;
        }

        return false;
    }
};

//O(m+n)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int& target)
    {
        int i=0, j=matrix.at(0).size()-1;

        while(i<matrix.size() && j>=0)
        {
            if(matrix[i][j]==target)
                return true;
            else if(matrix[i][j]>target)
                j--;
            else
                i++;
        }

        return false;
    }
};
