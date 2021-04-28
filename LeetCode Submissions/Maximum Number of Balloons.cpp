class Solution {
public:
    int maxNumberOfBalloons(string text)
    {
        int arr[15]={0};
        string k="balloon";

        for(auto z:text)
        {
            if(z-'a'<15)
                arr[z-'a']++;
        }

        int ans=0;
        bool done=false;
        while(1)
        {
            if(done)
                break;

            for(auto z:k)
            {
                if(arr[z-'a']==0)
                {
                    done=true;
                    break;
                }

                arr[z-'a']--;
            }

            if(!done)
                ans++;
        }

        return ans;
    }
};
