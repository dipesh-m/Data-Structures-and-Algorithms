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
class StackUsingLL
{
    Node<T>* head;
    int size;

public:
    StackUsingLL()
    {
        head=NULL;
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

    void push(T element)
    {
        Node<T>* newNode=new Node<T>(element);

        newNode->next=head;
        head=newNode;

        size++;
    }

    void pop()
    {
        if(isEmpty())
        {
            cout<<"STACK EMPTY"<<endl;
            return;
        }

        T a=head->data;

        Node<T>* temp=head;
        head=head->next;
        delete temp;

        size--;

        cout<<a<<" popped"<<endl;
    }

    T top()
    {
        if(isEmpty())
        {
            cout<<"STACK EMPTY"<<endl;
            return 0;
        }

        return head->data;
    }
};

int main()
{
    StackUsingLL<double> s;

    s.push(100.1);
    s.push(200.2);
    s.push(300.3);
    s.push(400.4);
    s.push(500.5);

    s.pop();
    s.pop();

    cout<<s.top()<<endl;
    cout<<s.getSize()<<endl;
    cout<<s.isEmpty()<<endl;
}
