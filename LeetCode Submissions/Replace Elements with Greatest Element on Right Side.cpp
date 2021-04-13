class Solution {
public:
    vector<int> replaceElements(vector<int>& arr)
    {
        int gr=arr.at(arr.size()-1);
        arr.at(arr.size()-1)=-1;

        for(int i=arr.size()-2; i>=0; i--)
        {
            int temp=arr.at(i);
            arr.at(i)=gr;
            gr=max(gr, temp);
        }

        return arr;
    }
};
