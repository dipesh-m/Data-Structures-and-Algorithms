//WITHOUT USING PRIORITY QUEUE
class Solution {
public:
    string reorganizeString(string S)
    {
        int arr[26]={0};
        for(auto& z:S)
            arr[z-'a']++;

        int maxFreq=INT_MIN, maxCharIdx;
        for(int i=0; i<26; i++)
        {
            if(arr[i]>maxFreq)
            {
                maxFreq=arr[i];
                maxCharIdx=i;
            }
        }

        if(maxFreq>(S.size()+1)/2)
            return "";

        int i=0;
        while(arr[maxCharIdx]>0)
        {
            S[i]='a'+maxCharIdx;
            arr[maxCharIdx]--;
            i+=2;
        }

        for(int j=0; j<26; j++)
        {
            while(arr[j]>0)
            {
                if(i>=S.size()) //if we cross the array..which may only happen once
                    i=1;

                S[i]='a'+j;
                arr[j]--;
                i+=2;
            }
        }

        return S;
    }
};

//USING PRIORITY QUEUE
class Solution {
public:
    string reorganizeString(string S)
    {
        int arr[26]={0};
        for(auto& z:S)
            arr[z-'a']++;

        priority_queue<pair<int, char>> pq;
        for(int i=0; i<26; i++)
        {
            if(arr[i]!=0)
                pq.push(make_pair(arr[i], 'a'+i));
        }

        int i=0;
        while(!pq.empty())
        {
            pair<int, char> p1=pq.top();
            pq.pop();

            S[i]=p1.second;
            p1.first--;
            i++;

            if(pq.empty())
            {
                if(p1.first>0)
                    return "";

                break;
            }

            pair<int, char> p2=pq.top();
            pq.pop();

            S[i]=p2.second;
            p2.first--;
            i++;

            if(p1.first>0)
                pq.push(p1);
            if(p2.first>0)
                pq.push(p2);
        }

        return S;
    }
};
