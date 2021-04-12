class Node
{
public:
    int val;
    Node* next;

    Node(int v)
    {
        val=v;
        next=NULL;
    }
};

class MyLinkedList {
public:
    Node* head;
    Node* tail;
    /** Initialize your data structure here. */
    MyLinkedList()
    {
        head=NULL;
        tail=NULL;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index)
    {
        Node* temp=head;
        for(int i=0; i<index; i++)
        {
            temp=temp->next;
            if(temp==NULL)
                return -1;
        }

        return temp->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val)
    {
        Node* newNode=new Node(val);

        if(head==NULL)
        {
            head=newNode;
            tail=newNode;

            return;
        }

        newNode->next=head;
        head=newNode;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val)
    {
        Node* newNode=new Node(val);

        if(head==NULL)
        {
            head=newNode;
            tail=newNode;

            return;
        }

        tail->next=newNode;
        tail=newNode;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val)
    {
        if(index==0)
        {
            addAtHead(val);
            return;
        }

        Node* temp=head;
        for(int i=0; i<index-1; i++)
        {
            temp=temp->next;
            if(temp==NULL)
                return;
        }

        Node* newNode=new Node(val);
        if(temp->next!=NULL)
        {
            newNode->next=temp->next;
            temp->next=newNode;
        }
        else
        {
            temp->next=newNode;
            tail=newNode;
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index)
    {
        if(index==0)
        {
            if(head->next==NULL)
            {
                delete head;
                head=NULL;
                tail=NULL;
            }
            else
            {
                Node* temp=head;
                head=head->next;
                delete temp;
            }

            return;
        }

        Node* temp=head;
        for(int i=0; i<index-1; i++)
        {
            temp=temp->next;
            if(temp==NULL || temp->next==NULL)
                return;
        }

        if(temp->next==NULL)
        {
            return;
        }

        if(temp->next->next==NULL)
        {
            tail=temp;
        }

        Node* rec=temp->next;
        temp->next=temp->next->next;
        delete rec;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
