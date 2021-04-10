class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int a=edges.at(0).at(0);
        int b=edges.at(0).at(1);

        if(edges.at(1).at(0)==a)
        {
            return a;
        }
        else if(edges.at(1).at(0)==b)
        {
            return b;
        }
        else if(edges.at(1).at(1)==a)
        {
            return a;
        }

        return b;

    }
};
