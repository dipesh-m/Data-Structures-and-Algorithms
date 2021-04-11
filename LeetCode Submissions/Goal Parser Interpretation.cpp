class Solution {
public:
    string interpret(string command)
    {
        string ans;
        int i=0;
        while(i<command.size())
        {
            if(command.at(i)=='G')
            {
                ans+="G";
                i++;
            }
            else if(command.at(i)=='(')
            {
                if(command.at(i+1)==')')
                {
                    ans+="o";
                    i+=2;
                }
                else
                {
                    ans+="al";
                    i+=4;
                }
            }
        }

        return ans;
    }
};
