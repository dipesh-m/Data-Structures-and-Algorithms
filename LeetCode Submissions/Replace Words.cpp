class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence)
    {
        unordered_set<string> us;
        for(auto z:dictionary)
            us.insert(z);

        string ans;
        int i=0;
        while(i<sentence.size())
        {
            string temp;
            bool notFound=true;
            while(i<sentence.size() && sentence.at(i)!=' ')
            {
                if(notFound)
                {
                    temp+=sentence.at(i);
                    if(us.count(temp)>0)
                    {
                        ans+=temp;
                        ans+=' ';
                        notFound=false;
                    }
                }

                i++;
            }

            if(notFound)
            {
                ans+=temp;
                ans+=' ';
            }

            i++;
        }

        if(ans.at(ans.size()-1)==' ')
            ans.pop_back();

        return ans;
    }
};
