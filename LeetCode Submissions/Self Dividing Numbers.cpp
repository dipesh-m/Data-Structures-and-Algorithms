class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right)
    {
        vector<int> ans;
        for(int num=left; num<=right; num++)
        {
            int temp=num;
            bool include=true;
            while(temp>0)
            {
                if(temp%10==0 || num%(temp%10)!=0)
                {
                    include=false;
                    break;
                }

                temp/=10;
            }

            if(include)
                ans.push_back(num);
        }

        return ans;
    }
};
