class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms)
    {
        unordered_set<int> keys;
        queue<int> q;

        q.push(0);

        while(!q.empty())
        {
            int fr=q.front();
            q.pop();

            if(keys.count(fr)==0)
            {
                for(auto& z:rooms[fr])
                    q.push(z);
            }

            keys.insert(fr);

            if(keys.size()==rooms.size())
                return true;
        }

        return false;
    }
};
