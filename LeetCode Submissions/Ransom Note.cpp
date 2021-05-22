class Solution {
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        int arr[26]={0};
        for(auto& z:magazine)
            arr[z-'a']++;

        for(auto& z:ransomNote)
        {
            if(--arr[z-'a']<0)
                return false;
        }

        return true;
    }
};
