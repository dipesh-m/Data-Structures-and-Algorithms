class Solution {
public:
    string arrangeWords(string text)
    {
        map<int, string> m;
        text[0]='a'+(text[0]-'A');

        int i=0;
        while(i<text.size())
        {
            string x;
            while(i<text.size() && text[i]!=' ')
            {
                x+=text[i];
                i++;
            }

            if(m.count(x.size())>0)
                m.at(x.size())+=' '+x;
            else
                m[x.size()]=x;

            i++;
        }

        string ans;
        for(auto& z:m)
            ans+=z.second+' ';

        ans[0]='A'+(ans[0]-'a');
        ans.pop_back();

        return ans;
    }
};
