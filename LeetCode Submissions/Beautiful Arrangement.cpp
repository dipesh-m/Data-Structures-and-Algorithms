class Solution {
public:
    bool check(int* arr, int r)
    {
        for(int i=0; i<=r; i++)
        {
            if(arr[i]%(i+1)!=0 && (i+1)%arr[i]!=0)
                return false;
        }

        return true;
    }

    void perm(int* arr, int l, int r, int& ans)
    {
        if(l==r)
        {
            if(check(arr, r))
                ans++;

            return;
        }

        for(int i=l; i<=r; i++)
        {
            if(arr[i]%(l+1)==0 || (l+1)%arr[i]==0)
            {
                swap(arr[l], arr[i]);
                perm(arr, l+1, r, ans);
                swap(arr[l], arr[i]);
            }
        }
    }

    int countArrangement(int n)
    {
        int* arr=new int[n];
        for(int i=0; i<n; i++)
            arr[i]=i+1;

        int ans=0;

        perm(arr, 0, n-1, ans);

        delete []arr;
        return ans;
    }
};
