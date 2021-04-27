class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2)
    {
        unordered_map<string, int> um;
        for(int i=0; i<list1.size(); i++)
            um[list1[i]]=i;

        int minSum=INT_MAX;
        string ans;
        for(int i=0; i<list2.size(); i++)
        {
            if(um.count(list2[i])>0 && (um.at(list2[i])+i)<minSum)
            {
                minSum=um.at(list2[i])+i;
                ans=list2[i];
            }
        }

        vector<string> re;
        for(int i=0; i<list2.size(); i++)
        {
            if(list2[i]!=ans && um.count(list2[i])>0 && (um.at(list2[i])+i)==minSum)
            {
                for(int j=0; j<list2.size(); j++)
                {
                    if(um.count(list2[j])>0)
                        re.push_back(list2[j]);
                }

                return re;
            }
        }

        re.push_back(ans);
        return re;
    }
};
