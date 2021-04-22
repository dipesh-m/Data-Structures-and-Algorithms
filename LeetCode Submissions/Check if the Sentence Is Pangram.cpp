class Solution {
public:
    bool checkIfPangram(string sentence)
    {
        int arr[26]={0};
        for(auto z:sentence)
            arr[z-'a']++;

        for(int i=0; i<26; i++)
        {
            if(arr[i]==0)
                return false;
        }

        return true;
    }
};
