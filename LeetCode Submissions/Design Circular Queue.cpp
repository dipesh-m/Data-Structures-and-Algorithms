class MyCircularQueue {
private:
    int* arr;
    int firstIndex;
    int nextIndex;
    int size;
    int capacity;
public:
    MyCircularQueue(int k)
    {
        arr=new int[k];
        firstIndex=-1;
        nextIndex=0;
        size=0;
        capacity=k;
    }

    bool enQueue(int value)
    {
        if(isFull())
            return false;

        arr[nextIndex]=value;
        nextIndex=(nextIndex+1)%capacity;

        if(firstIndex==-1)
            firstIndex=0;

        size++;
        return true;
    }

    bool deQueue()
    {
        if(isEmpty())
            return false;

        firstIndex=(firstIndex+1)%capacity;

        size--;
        if(size==0)
        {
            firstIndex=-1;
            nextIndex=0;
        }

        return true;
    }

    int Front()
    {
        if(isEmpty())
            return -1;

        return arr[firstIndex];
    }

    int Rear()
    {
        if(isEmpty())
            return -1;

        if(nextIndex==0)
            return arr[capacity-1];

        return arr[nextIndex-1];
    }

    bool isEmpty()
    {
        return size==0;
    }

    bool isFull()
    {
        return size==capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
