class Solution {
public:
    string reformatDate(string date)
    {
        string arr[13]={"", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        string ans[3];

        int i=0, j=2;
        while(i<date.size())
        {
            arr[0]="";
            while(i<date.size() && date[i]!=' ')
            {
                arr[0]+=date[i];
                i++;
            }

            if(j==2)
            {
                if(arr[0].size()<4)
                {
                    ans[j]+='0';
                    ans[j]+=arr[0][0];
                }

                else
                {
                    ans[j]+=arr[0][0];
                    ans[j]+=arr[0][1];
                }
            }
            else if(j==1)
            {
                for(int k=1; k<13; k++)
                {
                    if(arr[k]==arr[0])
                    {
                        if(k<=9)
                        {
                            ans[j]+='0';
                            ans[j]+='0'+k;
                        }
                        else
                        {
                            ans[j]+='1';
                            ans[j]+='0'+(k%10);
                        }

                        break;
                    }
                }
            }
            else
                ans[j]=arr[0];

            j--;
            i++;
        }

        date="";
        i=0;
        while(i<3)
        {
            date+=ans[i];
            date+='-';
            i++;
        }

        date.pop_back();

        return date;
    }
};
