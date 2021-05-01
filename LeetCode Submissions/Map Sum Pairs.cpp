//Prefix Map soln.
class MapSum {
private:
    unordered_map<string, int> um;
    unordered_map<string, int> prefixMap;
public:
    /** Initialize your data structure here. */
    MapSum(){}

    void insert(string key, int val)
    {
        int prev;
        if(um.count(key)>0)
            prev=um.at(key);
        else
            prev=0;

        string pre;
        for(int i=0; i<key.size(); i++)
        {
            pre+=key[i];
            prefixMap[pre]=prefixMap[pre]+val-prev;
        }

        um[key]=val;
    }

    int sum(string prefix)
    {
        return prefixMap.count(prefix)>0 ? prefixMap.at(prefix) : 0;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */

 // Brute force
 class MapSum {
private:
    unordered_map<string, int> um;
public:
    /** Initialize your data structure here. */
    MapSum(){}

    void insert(string key, int val)
    {
        um[key]=val;
    }

    int sum(string prefix)
    {
        int ans=0;
        for(auto& z:um)
        {
            if(z.first.substr(0, prefix.size())==prefix)
                ans+=z.second;
        }

        return ans;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
