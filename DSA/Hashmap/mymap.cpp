

//ONLY STRING IS SUPPORTED AS KEY AND IS PREDEFINED...ONLY PROVIDE TEMPLATE ARGUMENT FOR VALUE WHILE INSTANTIATING mymap


#include<iostream>
#include "mymap.h"
using namespace std;

int main()
{
    mymap<int> m;

    for(int i=0; i<10; i++)
    {
        char c='0'+i;
        string key="abc";
        key=key+c;
        int value=i+1;
        m.insert(key, value);
        cout<<m.getLoadFactor()<<endl;
    }

    cout<<m.size()<<endl;
    m.remove("abc2");
    m.remove("abc3");

    for(int i=0; i<10; i++)
    {
        char c='0'+i;
        string key="abc";
        key=key+c;
        cout<<key<<":"<<m.getValue(key)<<endl;
    }

    cout<<m.size()<<endl;
}
