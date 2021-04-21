class MagicDictionary {
public:
    /** Initialize your data structure here. */
    unordered_map<int, vector<string>> um;

    MagicDictionary()
    {
    }

    void buildDict(vector<string> dictionary)
    {
        for(auto z:dictionary)
        {
            if(um.count(z.size())>0)
            {
                um.at(z.size()).push_back(z);
            }
            else
            {
                vector<string> im;
                im.push_back(z);

                um[z.size()]=im;
            }
        }
    }

    bool search(string word)
    {
        if(um.count(word.size())==0)
        {
            return false;
        }

        vector<string>& vec=um.at(word.size());
        for(int i=0; i<vec.size(); i++)
        {
            string temp=vec.at(i);
            string wordTemp=word;;
            bool possible=false;
            for(int j=0; j<temp.size(); j++)
            {
                if(temp.at(j)!=wordTemp.at(j))
                {
                    wordTemp.at(j)=temp.at(j);
                    if(wordTemp==temp)
                    {
                        possible=true;
                    }

                    break;
                }
            }

            if(possible)
                return true;
        }

        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
