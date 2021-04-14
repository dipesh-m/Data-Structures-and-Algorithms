class Solution {
public:
    vector<string> printVertically(string s)
    {
        vector<string> ans;

        int rowSize=INT_MIN, colSize=0; //default if only 1 word

        int i=0;
        while(i<s.size())
        {
            int currWordSize=0;
            while(i<s.size() && s.at(i)!=' ')
            {
                currWordSize++;
                i++;
            }
            rowSize=max(rowSize, currWordSize);

            if(i==s.size() || s.at(i)==' ')
            {
                colSize++;
            }

            i++;
        }

        char** arr_2D=new char*[rowSize];
        for(int i=0; i<rowSize; i++)
        {
            arr_2D[i]=new char[colSize];
            for(int j=0; j<colSize; j++)
            {
                arr_2D[i][j]=' ';
            }
        }

        int k=0;
        for(int i=0; i<colSize; i++)
        {
            for(int j=0; j<rowSize; j++)
            {
                if(k==s.size() || s.at(k)==' ')
                    break;

                arr_2D[j][i]=s.at(k);
                k++;
            }

            k++;
        }

        for(int i=0; i<rowSize; i++)
        {
            string im;
            for(int j=0; j<colSize; j++)
            {
                im+=arr_2D[i][j];
            }

            int z=im.size()-1;
            while(im.at(z)==' ')
            {
                im.pop_back();
                z--;
            }

            ans.push_back(im);
        }

        return ans;
    }
};
