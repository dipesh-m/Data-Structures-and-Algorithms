class Solution {
public:
    bool isAnagram(string s, string t)
    {
        int arr[26]={0};
        for(auto z:s)
            arr[z-'a']++;

        for(auto z:t)
            arr[z-'a']--;

        for(auto z:arr)
        {
            if(z!=0)
                return false;
        }

        return true;
    }
};
