#include<iostream>
#include <climits>
using namespace std;

template<typename T>
class StackUsingArray
{
    T* data;
    int nextIndex;
    int capacity;

public:
    StackUsingArray(int totalSize)
    {
        data=new T[totalSize];
        nextIndex=0;
        capacity=totalSize;
    }

    int size()
    {
        return nextIndex;
    }

    bool isEmpty()
    {
        return nextIndex==0;
    }

    void push(T element)
    {
        if(nextIndex==capacity)
        {
            cout<<"STACK FULL"<<endl;
            return;
        }
        data[nextIndex]=element;
        nextIndex++;
    }

    void pop()
    {
        if(isEmpty())
        {
            cout<<"STACK EMPTY"<<endl;
        }
        nextIndex--;

        cout<<data[nextIndex]<<" popped"<<endl;;
    }

    T top()
    {
        if(isEmpty())
        {
            cout<<"STACK EMPTY"<<endl;
            return INT_MIN;
        }

        return data[nextIndex-1];
    }
};

int main()
{
    StackUsingArray<int> s(10);

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout<<s.top()<<endl;

    s.pop();
    s.pop();

    cout<<s.size()<<endl;

    cout<<s.isEmpty()<<endl;
}
