class Solution {
public:
    bool judgeCircle(string moves)
    {
        int up=0, down=0, left=0, right=0;
        for(auto z:moves)
        {
            if(z=='U')
                up++;
            else if(z=='D')
                down++;
            else if(z=='R')
                right++;
            else
                left++;
        }

        return (up-down==0) && (left-right==0);
    }
};
