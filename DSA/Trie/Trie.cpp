

//ONLY LOWERCASE ALPHABET LETTERS ARE SUPPORTED


#include<iostream>
#include "Trie.h"
using namespace std;

int main()
{
    Trie t;

    t.insertWord("hello");
    t.insertWord("world");

    cout<<t.searchWord("hello")<<endl;
    cout<<t.searchWord("world")<<endl;

    t.removeWord("hello");

    cout<<t.searchWord("hello")<<endl;
}
