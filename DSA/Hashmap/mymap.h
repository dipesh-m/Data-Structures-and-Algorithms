#include<string>
using namespace std;

template<typename V>
class mapNode
{
public:
    string key;
    V value;
    mapNode<V>* next;

    mapNode(string key, V value)
    {
        this->key=key;
        this->value=value;
        next=NULL;
    }

    ~mapNode()
    {
       delete next;
    }
};

template<typename V>
class mymap
{
   mapNode<V>** buckets;
   int count;
   int numBuckets;

public:
    mymap()
    {
        count=0;
        numBuckets=5;
        buckets=new mapNode<V>*[numBuckets];
        for(int i=0; i<numBuckets; i++)
        {
            buckets[i]=NULL;
        }
    }

    ~mymap()
    {
        for(int i=0; i<numBuckets; i++)
        {
            delete buckets[i];
        }

        delete []buckets;
    }

    int size()
    {
        return count;
    }

    V getValue(string key)
    {
        int bucketIndex=getBucketIndex(key);

        mapNode<V>* head=buckets[bucketIndex];
        while(head!=NULL)
        {
            if(head->key==key)
            {
                return head->value;
            }

            head=head->next;
        }

        return 0;
    }

private:
    int getBucketIndex(string key)
    {
        int hashCode=0;
        int currentCoeff=1;

        for(int i=key.length()-1; i>=0; i--)
        {
            hashCode+=key[i]*currentCoeff;
            hashCode=hashCode%numBuckets;
            currentCoeff*=37;
            currentCoeff=currentCoeff%numBuckets;
        }

        return hashCode%numBuckets;
    }

    void rehash()
    {
        mapNode<V>** temp=buckets;
        int oldBucketCount=numBuckets;

        buckets=new mapNode<V>*[2*numBuckets];
        for(int i=0; i<2*numBuckets; i++)
        {
            buckets[i]=NULL;
        }

        numBuckets*=2;
        count=0;

        for(int i=0; i<oldBucketCount; i++)
        {
            mapNode<V>* head=temp[i];
            while(head!=NULL)
            {
                string key=head->key;
                V value=head->value;
                insert(key, value);

                head=head->next;
            }
        }

        for(int i=0; i<oldBucketCount; i++)
        {
            mapNode<V>* head=temp[i];
            delete head;
        }

        delete []temp;
    }

public:
    double getLoadFactor()
    {
        return (1.0*count)/numBuckets;
    }

    void insert(string key, V value)
    {
        int bucketIndex=getBucketIndex(key);

        mapNode<V>* head=buckets[bucketIndex];
        while(head!=NULL)
        {
            if(head->key==key)
            {
                head->value=value;
                return;
            }

            head=head->next;
        }

        head=buckets[bucketIndex];
        mapNode<V>* newNode=new mapNode<V>(key, value);
        newNode->next=head;
        buckets[bucketIndex]=newNode;

        count++;

        double loadFactor=(1.0*count)/numBuckets;
        if(loadFactor>0.7)
        {
            rehash();
        }
    }

    V remove(string key)
    {
        int bucketIndex=getBucketIndex(key);
        mapNode<V>* head=buckets[bucketIndex];
        mapNode<V>* prev=NULL;

        while(head!=NULL)
        {
            if(head->key==key)
            {
                if(prev==NULL)
                {
                   buckets[bucketIndex]=head->next;
                }
                else
                {
                   prev->next=head->next;
                }

                V value=head->value;
                head->next=NULL;
                delete head;
                count--;

                return value;
            }

            prev=head;
            head=head->next;
        }

        return 0;
    }
};
