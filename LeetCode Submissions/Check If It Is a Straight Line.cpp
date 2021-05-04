class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& co)
    {
        int dy=co[1][1]-co[0][1];
        int dx=co[1][0]-co[0][0];

        int i=1;
        while(i+1<co.size())
        {
            if(dx*(co[i+1][1]-co[i][1]) != dy*(co[i+1][0]-co[i][0]))
                return false;

            i++;
        }

        return true;
    }
};
