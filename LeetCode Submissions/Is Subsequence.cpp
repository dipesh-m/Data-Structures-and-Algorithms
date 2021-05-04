//ORIGINAL SOLN.
class Solution {
public:
    bool isSubsequence(string s, string t)
    {
        int i=0, j=0;
        while(i<s.size() && j<t.size())
        {
            if(s[i]==t[j])
            {
                i++;
                j++;
            }
            else
                j++;
        }

        return i==s.size();
    }
};

//FOLLOW UP
class Solution {
public:
    bool isSubsequence(string s, string t)
    {
        unordered_map<char, vector<int>> um;
        for(int i=0; i<t.size(); i++)
            um[t[i]].push_back(i);

        int prevIdx=-1;
        for(int i=0; i<s.size(); i++)
        {
            if(um.count(s[i])==0)
                return false;

            vector<int>& vec=um.at(s[i]);

            int lo=0, hi=vec.size()-1, mid=-1;
            while(lo<=hi)
            {
                mid=lo+(hi-lo)/2;

                if((mid==0 || vec[mid-1]<=prevIdx) && vec[mid]>prevIdx)
                {
                    prevIdx=vec[mid];
                    break;
                }
                else if(prevIdx>=vec[mid])
                    lo=mid+1;
                else
                    hi=mid-1;
            }

            if(lo>hi)
                return false;
        }

        return true;
    }
};
