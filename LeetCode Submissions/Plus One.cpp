//IN-PLACE
class Solution {
public:
    vector<int> plusOne(vector<int>& digits)
    {
        int i=digits.size()-1;
        while(i>=0)
        {
            if(++digits[i]<10)
                return digits;
            else
                digits[i]=0;

            i--;
        }

        digits.insert(digits.begin(), 1);
        return digits;
    }
};

//USING O(N) SPACE where N=input arr size
class Solution {
public:
    vector<int> plusOne(vector<int>& digits)
    {
        int i=digits.size()-1;
        while(i>=0)
        {
            if(++digits[i]<10)
                return digits;
            else
                digits[i]=0;

            i--;
        }

        vector<int> res(digits.size()+1, 0);
        res[0]=1;
        return res;
    }
};
