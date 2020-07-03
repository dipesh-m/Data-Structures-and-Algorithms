#include<iostream>
using namespace std;

template<typename T>
class Node
{
public:
    T data;
    Node<T>* next;

    Node(T data)
    {
        this->data=data;
        next=NULL;
    }
};

template<typename T>
class QueueUsingLL
{
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    QueueUsingLL()
    {
        head=NULL;
        tail=NULL;
        size=0;
    }

    bool isEmpty()
    {
        return head==NULL;
    }

    int getSize()
    {
        return size;
    }

    void enqueue(T element)
    {
        Node<T>* newNode=new Node<T>(element);
        if(head==NULL)
        {
            head=newNode;
            tail=newNode;
        }
        else
        {
            tail->next=newNode;
            tail=newNode;
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

        T a=head->data;
        Node<T>* temp=head;
        head=head->next;
        delete temp;

        size--;

        cout<<a<<" dequeued"<<endl;
    }

    T front()
    {
        if(isEmpty())
        {
            cout<<"QUEUE EMPTY"<<endl;
            return 0;
        }

        return head->data;
    }
};

int main()
{
    QueueUsingLL<int> q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.dequeue();
    q.dequeue();

    cout<<q.front()<<endl;
    cout<<q.getSize()<<endl;
    cout<<q.isEmpty()<<endl;
}
