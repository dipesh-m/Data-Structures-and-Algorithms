class Solution {
public:
    int countCharacters(vector<string>& words, string chars)
    {
        vector<int> arr(26, 0);
        for(auto z:chars)
            arr[z-'a']++;

        int ans=0;
        for(auto z:words)
        {
            vector<int> temp(arr);
            bool include=true;

            for(auto k:z)
            {
                if(temp[k-'a']==0)
                {
                    include=false;
                    break;
                }

                temp[k-'a']--;
            }

            if(include)
                ans+=z.size();
        }

        return ans;
    }
};
