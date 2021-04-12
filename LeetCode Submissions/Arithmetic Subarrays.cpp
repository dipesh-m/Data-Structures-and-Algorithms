class Solution {
public:
    bool check(vector<int> v)
    {
        if(v.size()<=2)
            return true;

        int i=0, diff=abs(v.at(0)-v.at(1));
        while(i+1<v.size())
        {
            if(abs(v.at(i)-v.at(i+1))!=diff)
            {
                return false;
            }

            i++;
        }

        return true;
    }

    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r)
    {
        vector<bool> ans;

        for(int i=0; i<l.size(); i++)
        {
            vector<int> im(nums.begin()+l.at(i), nums.begin()+r.at(i)+1);
            sort(im.begin(), im.end());
            if(check(im))
                ans.push_back(1);
            else
                ans.push_back(0);
        }
        return ans;
    }
};
