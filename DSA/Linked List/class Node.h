#ifndef NODE
#define NODE

class Node
{
public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data=data;
        next=NULL;
    }
};

#endif // NODE
