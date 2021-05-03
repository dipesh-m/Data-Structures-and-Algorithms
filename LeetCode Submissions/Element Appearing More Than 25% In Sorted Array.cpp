class Solution {
public:
    int findSpecialInteger(vector<int>& arr)
    {
        if(arr.size()<4)
            return arr[0];

        int req=arr.size()/4;
        for(int i=0; i<arr.size(); i++)
        {
            if(arr[i]==arr[i+req])
                return arr[i];
        }

        return -1;
    }
};
