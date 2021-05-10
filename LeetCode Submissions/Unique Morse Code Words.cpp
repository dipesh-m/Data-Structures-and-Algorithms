class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words)
    {
        string arr[26]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

        unordered_set<string> us;
        int ans=0;
        for(auto& z:words)
        {
            string temp;
            for(auto& x:z)
                temp+=arr[x-'a'];

            us.insert(temp);
        }

        return us.size();
    }
};
