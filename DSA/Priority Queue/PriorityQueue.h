#include<vector>
using namespace std;

class PriorityQueue
{
private:
    vector<int> pq;

public:
    PriorityQueue(){}

    bool isEmpty()
    {
        return pq.size()==0;
    }

    int getSize()
    {
        return pq.size();
    }

    int getMin()
    {
        if(isEmpty())
        {
            return 0;
        }

        return pq[0];
    }

    void insert(int element)
    {
        pq.push_back(element);

        int i=pq.size()-1;
        int j=(i-1)/2;
        while(i>0)
        {
            if(pq[i]<pq[j])
            {
                int temp=pq[j];
                pq[j]=pq[i];
                pq[i]=temp;
            }
            else
            {
                break;
            }

            i=j;
            j=(i-1)/2;
        }
    }

    int removeMin()
    {
        if(isEmpty())
        {
            return 0;
        }

        int ans=pq[0];
        pq[0]=pq[pq.size()-1];
        pq.pop_back();

        int i=0;
        int j=2*i + 1;
        int k=2*i + 2;
        while(j<pq.size())
        {
            int minIndex=i;

            if(pq[minIndex]>pq[j])
            {
                minIndex=j;
            }

            if(k<pq.size() && pq[k]<pq[minIndex])
            {
                minIndex=k;
            }

            if(minIndex==i)
            {
                break;
            }

            int temp=pq[minIndex];
            pq[minIndex]=pq[i];
            pq[i]=temp;

            i=minIndex;
            j=2*i + 1;
            k=2*i + 2;
        }

        return ans;
    }
};
