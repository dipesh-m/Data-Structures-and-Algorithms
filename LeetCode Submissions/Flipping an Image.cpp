class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image)
    {
        for(int i=0; i<image.size(); i++)
        {
            int f=0, s=image[i].size()-1;
            while(f<s)
            {
                if(image[i][f]==image[i][s])
                {
                    image[i][f]^=1;
                    image[i][s]^=1;
                }

                f++;
                s--;
            }

            if(f==s)
                image[i][f]^=1;
        }

        return image;
    }
};
