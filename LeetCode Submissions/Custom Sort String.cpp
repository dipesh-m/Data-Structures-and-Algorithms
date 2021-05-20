class Solution {
public:
    string customSortString(string S, string T)
    {
        unordered_map<char, int> um;
        for(auto& z:T)
            um[z]++;

        int k=0;
        for(auto& z:S)
        {
            if(um.find(z)!=um.end())
            {
                while(um[z]>0)
                {
                    T[k]=z;
                    k++;
                    um[z]--;
                }
            }
        }

        for(auto& z:um)
        {
            while(z.second>0)
            {
                T[k]=z.first;
                k++;
                z.second--;
            }
        }

        return T;
    }
};
