class Solution {
public:
    char findTheDifference(string s, string t)
    {
        int arr[26]={0};

        for(auto z:s)
            arr[z-'a']++;

        for(auto z:t)
            arr[z-'a']--;

        for(int i=0; i<26; i++)
        {
            if(arr[i]!=0)
                return (char)i+'a';
        }

        return 0;
    }
};
