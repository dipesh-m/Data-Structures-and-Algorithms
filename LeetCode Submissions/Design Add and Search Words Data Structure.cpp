class TrieNode
{
public:
    char val;
    TrieNode** children;
    bool isTerminal;

    TrieNode(char val)
    {
        this->val=val;
        children=new TrieNode*[26];
        for(int i=0; i<26; i++)
            children[i]=NULL;
        isTerminal=false;
    }
};

class WordDictionary {
private:
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    WordDictionary()
    {
        root=new TrieNode('/');
    }
private:
    void addWordHelper(TrieNode* root, string word)
    {
        if(word.size()==0)
        {
            root->isTerminal=true;
            return;
        }

        int idx=word.at(0)-'a';
        TrieNode* child=NULL;

        if(root->children[idx]!=NULL)
            child=root->children[idx];
        else
        {
            child=new TrieNode(word.at(0));
            root->children[idx]=child;
        }

        addWordHelper(child, word.substr(1));
    }
public:
    void addWord(string word)
    {
        addWordHelper(root, word);
    }
private:
    bool searchHelper(TrieNode* root, string word)
    {
        if(word.size()==0)
        {
            if(root->isTerminal==true)
                return true;

            return false;
        }

        if(word.at(0)!='.')
        {
            int idx=word.at(0)-'a';
            TrieNode* child=NULL;

            if(root->children[idx]==NULL)
                return false;
            else
            {
                child=root->children[idx];
                if(searchHelper(child, word.substr(1)))
                    return true;
            }

            return false;
        }
        else
        {
            TrieNode* child;
            for(int i=0; i<26; i++)
            {
                if(root->children[i]!=NULL)
                {
                    child=root->children[i];
                    if(searchHelper(child, word.substr(1)))
                        return true;
                }
            }

            return false;
        }
    }
public:
    bool search(string word)
    {
        return searchHelper(root, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
