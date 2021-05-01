class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2)
    {
        map<int, int> m;
        for(auto& z:arr1)
            m[z]++;

        int i=0;
        for(auto& z:arr2)
        {
            for(int j=0; j<m.at(z); j++)
            {
                arr1[i]=z;
                i++;
            }

            m.at(z)=-1;
        }

        for(auto it=m.begin(); it!=m.end(); it++)
        {
            if(it->second!=-1)
            {
                for(int j=0; j<it->second; j++)
                {
                    arr1[i]=it->first;
                    i++;
                }
            }
        }

        return arr1;
    }
};
