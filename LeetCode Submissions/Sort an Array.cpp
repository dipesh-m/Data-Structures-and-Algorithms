class Solution {
public:
    vector<int> sortArray(vector<int>& nums)
    {
        if(nums.size()<=1)
            return nums;

        if(nums.size()==2)
        {
            if(nums.at(0)>nums.at(1))
            {
                swap(nums.at(0), nums.at(1));
                return nums;
            }
            return nums;
        }

        for(int i=1; i<nums.size(); i++)
        {
            int childIndex=i;
            int parentIndex=(childIndex-1)/2;

            while(childIndex>0)
            {
                if(nums.at(childIndex)>nums.at(parentIndex))
                {
                    swap(nums.at(parentIndex), nums.at(childIndex));
                }
                else
                {
                    break;
                }

                childIndex=parentIndex;
                parentIndex=(childIndex-1)/2;
            }
        }

        for(int heapLast=(nums.size())-1; heapLast>=0; heapLast--)
        {
            swap(nums.at(0), nums.at(heapLast));

            int parentIndex=0;
            int leftChildIndex=(2*parentIndex)+1;
            int rightChildIndex=(2*parentIndex)+2;

            while(leftChildIndex<heapLast)
            {
                int maxIndex=parentIndex;
                if(nums.at(leftChildIndex)>nums.at(maxIndex))
                {
                    maxIndex=leftChildIndex;
                }

                if(rightChildIndex<heapLast && nums.at(rightChildIndex)>nums.at(maxIndex))
                {
                    maxIndex=rightChildIndex;
                }

                if(maxIndex==parentIndex)
                {
                    break;
                }

                swap(nums.at(parentIndex), nums.at(maxIndex));

                parentIndex=maxIndex;
                leftChildIndex=(2*parentIndex)+1;
                rightChildIndex=(2*parentIndex)+2;
            }
        }

        return nums;
    }
};
