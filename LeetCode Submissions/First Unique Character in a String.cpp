class Solution {
public:
    int firstUniqChar(string s)
    {
        int arr[26]={0};

        for(auto z:s)
            arr[z-'a']++;

        for(int i=0; i<s.size(); i++)
        {
            if(arr[s.at(i)-'a']==1)
                return i;
        }

        return -1;
    }
};
