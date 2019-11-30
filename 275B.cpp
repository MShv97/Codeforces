/*
Convex Shape
https://codeforces.com/problemset/problem/275/B
Solved by: Mohammad Shehab
codeforces handle : MShv97
*/

#include<bits/stdc++.h>
using namespace std;

int cnt=0;
char s[55][55];
int n,m;
bool inside(int i,int j)
{
    return i<n && i>=0 && j<m && j>=0;
}
int di[]= {1,0,0,-1};
int dj[]= {0,1,-1,0};
bool vis[55][55];
bool counted[55][55];
void dfs(int i,int j,int h,int v)
{
    if(vis[i][j])
        return;
    vis[i][j]=1;
    if(!counted[i][j]) cnt++;
    counted[i][j]=1;
    for(int k=0; k<4; k++)
    {
        int vv=v,hh=h;
        int ii = i+di[k];
        int jj = j+dj[k];
        if(k==0 || k==3)
        {
            if(h&&v && v==1)
                continue;
            if(h)
                v=2;
            else
                v=1;
        }
        else if(k==1 || k==2)
        {
            if(h&&v && h==1)
                continue;
            if(v)
                h=2;
            else
                h=1;
        }
        if(inside(ii,jj) && s[ii][jj]=='B')
            dfs(ii,jj,h,v);
        v=vv;
        h=hh;
    }
    vis[i][j]=0;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++)
        scanf("%s",&s[i]);
    vector<pair<int,int>> p;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(s[i][j]=='B')
                p.push_back({i,j});

    bool res =1;
    for(int i=0; i<p.size() &&res; i++)
    {
        memset(vis,0,sizeof vis);
        memset(counted,0,sizeof counted);
        cnt=0;
        dfs(p[i].first,p[i].second,0,0);
        if(cnt!=p.size())
            res=0;
    }

    if(res)
        printf("YES");
    else
        printf("NO");

    return 0;
}
