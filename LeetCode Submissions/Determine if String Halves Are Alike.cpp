class Solution {
public:
    bool halvesAreAlike(string s)
    {
        string a=s.substr(0, s.size()/2);
        string b=s.substr(s.size()/2, s.size()/2);

        int ac=0, bc=0;
        for(auto z:a)
        {
            if(z=='a' || z=='e' || z=='i' || z=='o' || z=='u' || z=='A' || z=='E' || z=='I' || z=='O' || z=='U')
                ac++;
        }

        for(auto z:b)
        {
            if(z=='a' || z=='e' || z=='i' || z=='o' || z=='u' || z=='A' || z=='E' || z=='I' || z=='O' || z=='U')
                bc++;
        }

        return ac==bc;
    }
};
