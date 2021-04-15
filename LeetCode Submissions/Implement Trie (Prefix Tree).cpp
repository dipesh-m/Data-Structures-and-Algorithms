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

class Trie {
public:
    TrieNode* root;
    /** Initialize your data structure here. */
    Trie()
    {
        root=new TrieNode('/0');
    }

    /** Inserts a word into the trie. */
    void insertHelper(string word, TrieNode* root)
    {
        if(word.size()==0)
        {
            root->isTerminal=true;
            return;
        }

        char x=word.at(0);
        TrieNode* child=NULL;
        if(root->children[x-'a']!=NULL)
        {
            child=root->children[x-'a'];
        }
        else
        {
            child=new TrieNode(x);
            root->children[x-'a']=child;
        }

        insertHelper(word.substr(1), child);
    }

    void insert(string word)
    {
        insertHelper(word, root);
    }

    /** Returns if the word is in the trie. */
    bool searchHelper(string word, TrieNode* root, bool pref)
    {
        if(word.size()==0)
        {
            if(pref==true)
            {
                return true;
            }

            return root->isTerminal;
        }

        char x=word.at(0);
        TrieNode* child=NULL;
        if(root->children[x-'a']!=NULL)
        {
            child=root->children[x-'a'];
        }
        else
        {
            return false;
        }

        return searchHelper(word.substr(1), child, pref);
    }

    bool search(string word)
    {
        return searchHelper(word, root, false);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        return searchHelper(prefix, root, true);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
