class UndergroundSystem {
private:
    unordered_map<string, pair<int,int>> ans;
    unordered_map<int, pair<string,int>> checkInMap;
public:
    UndergroundSystem() {}

    void checkIn(int id, string stationName, int t)
    {
        checkInMap[id]=make_pair(stationName,t);
    }

    void checkOut(int id, string endStation, int t)
    {
        string stations=checkInMap.at(id).first+">"+endStation;

        if(ans.count(stations)>0)
        {
            ans.at(stations).first+=t-checkInMap.at(id).second;
            ans.at(stations).second++;
        }
        else
            ans[stations]=make_pair((t-checkInMap.at(id).second),1);
    }

    double getAverageTime(string startStation, string endStation)
    {
        return ((double)ans.at(startStation+">"+endStation).first / (double)ans.at(startStation+">"+endStation).second);
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
