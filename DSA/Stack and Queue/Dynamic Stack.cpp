#include<iostream>
using namespace std;

template<typename T>
class DynamicStack
{
    T* data;
    int nextIndex;
    int capacity;

public:
    DynamicStack()
    {
        data=new T[4];
        nextIndex=0;
        capacity=4;
    }

    bool isEmpty()
    {
        return nextIndex==0;
    }

    int getSize()
    {
        return nextIndex;
    }

    void push(T element)
    {
        if(nextIndex==capacity)
        {
            T* newData=new T[capacity*2];
            for(int i=0; i<capacity; i++)
            {
                newData[i]=data[i];
            }

            data=newData;
            delete []data;
            capacity=capacity*2;
        }

        data[nextIndex]=element;
        nextIndex++;
    }

    void pop()
    {
        if(isEmpty())
        {
            cout<<"STACK EMPTY"<<endl;
            return;
        }

        nextIndex--;

        cout<<data[nextIndex]<<" popped"<<endl;
    }

    T top()
    {
        if(isEmpty())
        {
            cout<<"STACK EMPTY"<<endl;
            return 0;
        }

        return data[nextIndex-1];
    }
};

int main()
{
    DynamicStack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70);
    s.push(80);

    s.pop();
    s.pop();

    cout<<s.top()<<endl;
    cout<<s.getSize()<<endl;
    cout<<s.isEmpty()<<endl;
}
