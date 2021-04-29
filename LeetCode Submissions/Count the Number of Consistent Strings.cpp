class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words)
    {
        vector<int> arr(26, 0);
        for(auto z:allowed)
            arr[z-'a']++;

        int ans=0;
        for(auto z:words)
        {
            bool include=true;
            for(auto k:z)
            {
                if(arr[k-'a']==0)
                {
                    include=false;
                    break;
                }
            }

            if(include)
                ans++;
        }

        return ans;
    }
};
