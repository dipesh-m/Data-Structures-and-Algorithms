//USING FREQUENCY MAP AND TWO POINTERS
class Solution {
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> ans;

        if(p.length()>s.length())
            return ans;

        unordered_map<char, int> um;
        for(auto& z:p)
            um[z]++;

        int begin=0, end=0, counter=um.size();
        while(end<s.length())
        {
            if(um.count(s[end])>0)
            {
                um.at(s[end])--;
                if(um.at(s[end])==0)
                    counter--;
            }

            while(counter==0)
            {
                if(um.count(s[begin])>0)
                {
                    if(um.at(s[begin])==0)
                        counter++;
                    um.at(s[begin])++;
                }

                if(end-begin+1==p.length())
                    ans.push_back(begin);

                begin++;
            }

            end++;
        }

        return ans;
    }
};

// USING FREQUENCY ARRAY
class Solution {
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> ans;

        if(s.size()<p.size())
            return ans;

        vector<int> arr(26,0);
        for(auto& z:p)
            arr[z-'a']++;

        int i=0, n=p.size();
        while(i<n)
        {
            arr[s[i]-'a']--;
            i++;
        }

        bool add=true;
        for(auto& z:arr)
        {
            if(z!=0)
            {
                add=false;
                break;
            }
        }

        if(add)
            ans.push_back(0);

        while(i<s.size())
        {
            arr[s[i-n]-'a']++;
            arr[s[i]-'a']--;

            add=true;
            for(auto& z:arr)
            {
                if(z!=0)
                {
                    add=false;
                    break;
                }
            }

            if(add)
                ans.push_back(i-n+1);

            i++;
        }

        return ans;
    }
};
