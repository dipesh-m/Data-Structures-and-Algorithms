#include <iostream>
using namespace std;

template<typename T>
class QueueUsingArray
{
    T* data;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;

public:
    QueueUsingArray(int s)
    {
        data=new T[s];
        nextIndex=0;
        firstIndex=-1;
        size=0;
        capacity=s;
    }

    bool isEmpty()
    {
        return size==0;
    }

    int getSize()
    {
        return size;
    }

    void enqueue(T element)
    {
        if(size==capacity)
        {
            cout<<"QUEUE FULL"<<endl;
            return;
        }

        data[nextIndex]=element;
        nextIndex=(nextIndex+1)%capacity;

        if(firstIndex==-1)
        {
            firstIndex=0;
        }

        size++;
    }

    void dequeue()
    {
        if(isEmpty())
        {
            cout<<"QUEUE EMPTY"<<endl;
            return;
        }
        T ans=data[firstIndex];
        firstIndex=(firstIndex+1)%capacity;
        size--;

        if(size==0)
        {
            firstIndex=-1;
            nextIndex=0;
        }

        cout<<ans<<" dequeued"<<endl;
    }

    T front()
    {
        if(isEmpty())
        {
            cout<<"QUEUE EMPTY"<<endl;
            return 0;
        }

        return data[firstIndex];
    }
};

int main()
{
    QueueUsingArray<char> q(5);

    q.enqueue('a');
    q.enqueue('b');
    q.enqueue('c');
    q.enqueue('d');
    q.enqueue('e');
    q.enqueue('f');

    q.dequeue();
    q.dequeue();
    q.dequeue();

    cout<<q.front()<<endl;
    cout<<q.getSize()<<endl;
    cout<<q.isEmpty()<<endl;
}
