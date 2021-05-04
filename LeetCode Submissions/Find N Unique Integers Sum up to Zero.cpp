class Solution {
public:
    vector<int> sumZero(int n)
    {
        vector<int> ans;

        int i=0;
        if(n%2!=0)
        {
            ans.push_back(0);
            i++;
        }

        int x=-1000;
        while(i<n)
        {
            ans.push_back(x);
            ans.push_back(-x);
            x++;
            i+=2;
        }

        return ans;
    }
};
