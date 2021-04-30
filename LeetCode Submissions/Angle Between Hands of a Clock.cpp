class Solution {
public:
    double angleClock(int hour, int minutes)
    {
        if(hour==12)
            hour=0;

        double minDeg=minutes*(6.0);    //6 degree per minute is speed of minute hand
        double hourDeg=(hour*30.0)+(minutes*0.5);   //hour hand does 30 degree every hour(because 0.5*60) and its speed is 0.5 degree per minute

        return min(abs(hourDeg-minDeg), abs(360.0-abs(hourDeg-minDeg)));
    }
};
