/*
Spoilt Permutation
https://codeforces.com/problemset/problem/56/B
Solved by: Mohammad Shehab
codeforces handle : MShv97
*/

//method 1
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int n;
    scanf("%d",&n);
    int a[1005];
    for(int i=1; i<=n; i++)
        cin>>a[i];
 
    int l=0,r=0;
    for(int i=1; i<=n; i++)
        if(a[i]!=i)
        {
            l=i;
            r=a[i];
            reverse(a+i,a+a[i]+1);
            break;
        }
    for(int i=1; i<=n; i++)
        if(a[i]!=i)
        {
            l=0;
            r=0;
            break;
        }
 
    printf("%d %d",l,r);
 
    return 0;
}

//method 2
#include<bits/stdc++.h> 
using namespace std;
 
int main()
{
    int n;
    scanf("%d",&n);
    pair<int,int> p[1005];
    for(int i=1;i<=n;i++){
        cin>>p[i].first;
        p[i].second = i;
    }
    sort(p+1,p+n+1);
    int l=0,r=0;
    for(int i=1;i<=n;i++){
        if(p[i].second != i && !l) l=i;
        if(p[i].second != i && l ) r=i;
    }
    reverse(p+l,p+r+1);
    for(int i=1;i<=n;i++)
        if(p[i].second != i){l=0; r=0; break;}
 
    printf("%d %d",l,r);
 
    return 0;
}
