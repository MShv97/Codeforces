/*
Array
https://codeforces.com/problemset/problem/224/B
Solved by: Mohammad Shehab
codeforces handle : MShv97
*/
#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+100;
int a[N];
int cnt[N];
int main()
{
    int n,k,c=0;
    scanf("%d%d",&n,&k);
    int l=0,r=-1;
    for(int i=0; i<n; i++)
    {
        scanf("%d",a+i);
        if(cnt[a[i]]==0) c++;
        if(c==k && r==-1)
        {
            r=i;
            cnt[a[i]]++;
        }
        else if(r==-1)
            cnt[a[i]]++;
    }
    if(c<k)
        printf("-1 -1");
    else
    {
        while(cnt[a[l]]>1)
        {
            cnt[a[l]]--;
            l++;
        }
        printf("%d %d",l+1,r+1);
    }

    return 0;
}
