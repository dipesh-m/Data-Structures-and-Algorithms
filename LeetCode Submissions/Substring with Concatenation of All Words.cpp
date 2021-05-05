class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words)
    {
        vector<int> ans;

        int n=words.at(0).size();
        int totalLength=n*words.size();

        unordered_map<char, int> um;
        unordered_map<string, pair<int,int>> fr;
        for(auto& z:words)
        {
            if(fr.count(z)>0)
            {
                fr.at(z).second++;
                fr.at(z).first=fr.at(z).second;
            }
            else
            {
                pair<int,int> p;
                p.first=1;
                p.second=1;

                fr[z]=p;
            }

            for(auto& x:z)
                um[x]++;
        }

        int begin=0, end=0, counter=um.size();
        while(end<s.size())
        {
            if(um.count(s[end])>0)
            {
                um.at(s[end])--;
                if(um.at(s[end])==0)
                    counter--;
            }

            end++;

            while(counter==0)
            {
                if(um.count(s[begin])>0)
                {
                    if(um.at(s[begin])==0)
                        counter++;
                    um.at(s[begin])++;

                    if(end-begin==totalLength)
                    {
                        int totalStrings=fr.size();
                        int start=begin;
                        while(start<end)
                        {
                            string x=s.substr(start, n);
                            if(fr.count(x)>0)
                            {
                                fr.at(x).first--;
                                if(fr.at(x).first==0)
                                    totalStrings--;
                            }
                            else
                                break;

                            start+=n;
                        }

                        if(totalStrings==0)
                            ans.push_back(begin);

                        for(auto it=fr.begin(); it!=fr.end(); it++)
                            it->second.first=it->second.second;
                    }
                }

                begin++;
            }
        }

        return ans;
    }
};
