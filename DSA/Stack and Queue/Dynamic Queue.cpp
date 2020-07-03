#include <iostream>
using namespace std;

template<typename T>
class DynamicQueue
{
    T* data;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;

public:
    DynamicQueue()
    {
        data=new int[4];
        nextIndex=0;
        firstIndex=-1;
        size=0;
        capacity=4;
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
            T* newData=new T[capacity*2];

            int k=0;
            for(int i=firstIndex; i<capacity; i++)
            {
                newData[k]=data[i];
                k++;
            }
            for(int i=0; i<firstIndex; i++)
            {
                newData[k]=data[i];
                k++;
            }

            delete []data;
            data=newData;

            firstIndex=0;
            nextIndex=capacity;
            capacity*=2;
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
    DynamicQueue<int> q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70);
    q.enqueue(80);

    q.dequeue();
    q.dequeue();

    cout<<q.front()<<endl;
    cout<<q.getSize()<<endl;
    cout<<q.isEmpty()<<endl;
}

