#include "TrieNode.h"
#include<string>
using namespace std;

class Trie
{
    TrieNode* root;

public:
    Trie()
    {
        root=new TrieNode('\0');
    }

    ~Trie()
    {
        delete root;
    }

private:
    void insertWordHelper(TrieNode* root, string word)
    {
        if(word.size()==0)
        {
            root->isTerminal=true;
            return;
        }

        int index=word[0]-'a';
        TrieNode* child;
        if(root->children[index]!=NULL)
        {
            child=root->children[index];
        }
        else
        {
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }

        insertWordHelper(child, word.substr(1));
    }

public:
    void insertWord(string word)
    {
        insertWordHelper(root, word);
    }

private:
    bool searchWordHelper(TrieNode* root, string word)
    {
        if(word.size()==0)
        {
            return root->isTerminal;
        }

        int index=word[0]-'a';
        TrieNode* child;
        if(root->children[index]!=NULL)
        {
            child=root->children[index];
        }
        else
        {
            return false;
        }

        return searchWordHelper(child, word.substr(1));
    }

public:
    bool searchWord(string word)
    {
        return searchWordHelper(root, word);
    }

private:
    void removeWordHelper(TrieNode* root, string word)
    {
        if(word.size()==0)
        {
            root->isTerminal=false;
            return;
        }

        int index=word[0]-'a';
        TrieNode* child;
        if(root->children[index]!=NULL)
        {
            child=root->children[index];
        }
        else
        {
            return;
        }

        removeWordHelper(child, word.substr(1));

        if(child->isTerminal==false)
        {
            for(int i=0; i<26; i++)
            {
                if(child->children[i]!=NULL)
                {
                    return;
                }
            }

            delete child;
            root->children[index]=NULL;
        }
    }

public:
    void removeWord(string word)
    {
        removeWordHelper(root, word);
    }
};
