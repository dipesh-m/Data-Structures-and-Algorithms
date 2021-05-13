//WITHOUT USING PRIORITY QUEUE
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes)
    {
        unordered_map<int,int> um;
        for(auto& z:barcodes)
            um[z]++;

        int maxFreq=INT_MIN, maxFreqEle;
        for(auto& z:um)
        {
            if(z.second>maxFreq)
            {
                maxFreq=z.second;
                maxFreqEle=z.first;
            }
        }

        int i=0;
        while(um[maxFreqEle]>0)
        {
            barcodes[i]=maxFreqEle;
            um[maxFreqEle]--;
            i+=2;
        }

        for(auto& z:um)
        {
            while(z.second>0)
            {
                if(i>=barcodes.size())
                    i=1;

                barcodes[i]=z.first;
                z.second--;
                i+=2;
            }
        }

        return barcodes;
    }
};

//USING PRIORITY QUEUE
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes)
    {
        unordered_map<int,int> um;
        for(auto& z:barcodes)
            um[z]++;

        priority_queue<pair<int,int>> pq;
        for(auto& z:um)
            pq.push(make_pair(z.second, z.first));

        int i=0;
        while(!pq.empty())
        {
            pair<int,int> p1=pq.top();
            pq.pop();

            barcodes[i]=p1.second;
            p1.first--;
            i++;

            if(pq.empty() && p1.first==0)
                break;

            pair<int,int> p2=pq.top();
            pq.pop();

            barcodes[i]=p2.second;
            p2.first--;
            i++;

            if(p1.first>0)
                pq.push(p1);
            if(p2.first>0)
                pq.push(p2);
        }

        return barcodes;
    }
};
