class SeatManager {
private:
    priority_queue<int, vector<int>, greater<int>> lastUnreserved;
    int lowest=1;
public:
    SeatManager(int n) {}

    int reserve()
    {
        int ans;
        if(lastUnreserved.size()!=0)
        {
            ans=lastUnreserved.top();
            lastUnreserved.pop();
        }
        else
        {
            ans=lowest;
            lowest++;
        }

        return ans;
    }

    void unreserve(int seatNumber)
    {
        lastUnreserved.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
