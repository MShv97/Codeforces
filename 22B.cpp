/*
Bargaining Table
https://codeforces.com/contest/22/problem/B

Solved with O((n^2)*m) complexity.

Solved by: Mohammad Shehab
codeforces handle : MShv97
*/

#include<bits/stdc++.h>
 
using namespace std;
 
int h[30][30];
int rect[30];
char a[30][30];
 
void check(int i,int j)
{
    if(i-1<0)
        h[i][j]=1;
    else if(a[i-1][j]=='1')
        h[i][j]=1;
    else
        h[i][j]= h[i-1][j] +1;
}
 
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++)
        scanf("%s",&a[i]);
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(a[i][j]=='0')
                check(i,j);
 
    for(int k=1; k<=n; k++)
        for(int i=0; i<n; i++)
        {
            int cnt =0;
            for(int j=0; j<m; j++)
                if(h[i][j]>=k)
                    cnt++;
                else
                {
                    rect[k] = max(rect[k],cnt);
                    cnt=0;
                }
            rect[k] = max(rect[k],cnt);
        }
 
    int res =0;
    for(int i=1; i<=n; i++)
        if(rect[i])
            res = max(res,(i+rect[i])*2);
 
    printf("%d",res);
 
    return 0;
}
