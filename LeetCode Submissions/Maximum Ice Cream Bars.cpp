class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins)
    {
        sort(costs.begin(), costs.end());

        int ans=0;
        for(auto z:costs)
        {
            if(coins>=z)
            {
                ans++;
                coins-=z;
            }
            else
                break;
        }

        return ans;
    }
};
