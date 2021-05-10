class Solution {
public:
    string sortString(string s)
    {
        int arr[26]={0}, total=0;
        for(auto& z:s)
        {
            arr[z-'a']++;
            total++;
        }

        string ans;
        while(total>0)
        {
            for(int i=0; i<26; i++)
            {
                if(arr[i]!=0)
                {
                    ans+='a'+i;
                    arr[i]--;
                    total--;
                }
            }

            if(total==0)
                break;

            for(int i=25; i>=0; i--)
            {
                if(arr[i]!=0)
                {
                    ans+='a'+i;
                    arr[i]--;
                    total--;
                }
            }
        }

        return ans;
    }
};
