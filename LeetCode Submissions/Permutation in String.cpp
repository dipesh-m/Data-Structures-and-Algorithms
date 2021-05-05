//USING FREQUENCY VECTOR OF SIZE 26
class Solution {
public:
    bool checkInclusion(string s1, string s2)
    {
        if(s1.size()>s2.size())
            return false;

        vector<int> um(26,0);
        for(auto& z:s1)
            um[z-'a']++;

        int i=0, n=s1.size();
        while(i<s1.size())
        {
            um[s2[i]-'a']--;
            i++;
        }

        bool add=true;
        for(auto& z:um)
        {
            if(z!=0)
            {
                add=false;
                break;
            }
        }

        if(add)
            return true;

        while(i<s2.size())
        {
            um[s2[i-n]-'a']++;
            um[s2[i]-'a']--;

            add=true;
            for(auto& z:um)
            {
                if(z!=0)
                {
                    add=false;
                    break;
                }
            }

            if(add)
                return true;

            i++;
        }

        return false;
    }
};

//USING FREQUENCY MAP AND 2 POINTERS
class Solution {
public:
    bool checkInclusion(string s1, string s2)
    {
        if(s1.size()>s2.size())
            return false;

        unordered_map<char, int> um;
        for(auto& z:s1)
            um[z]++;

        int end=0, begin=0, counter=um.size();
        while(end<s2.length())
        {
            if(um.count(s2[end])>0)
            {
                um.at(s2[end])--;
                if(um.at(s2[end])==0)
                    counter--;
            }

            end++;

            while(counter==0)
            {
                if(um.count(s2[begin])>0)
                {
                    if(um.at(s2[begin])==0)
                        counter++;
                    um.at(s2[begin])++;
                }

                if(end-begin==s1.size())
                    return true;

                begin++;
            }
        }

        return false;
    }
};
