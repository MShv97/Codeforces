/*
Pocket Book
https://codeforces.com/problemset/problem/152/C
Solved by: Mohammad Shehab
codeforces handle : MShv97
*/

#include<bits/stdc++.h>

using namespace std;

const int mod = 1e9+7;

set<char> st[105];
char names[105][105];

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++)
        scanf("%s",names[i]);
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            st[j].insert(names[i][j]);

    long long res =1;
    for(int i=0;i<m;i++){
        res*=st[i].size();
        res%=mod;
    }

    printf("%lld",res);

    return 0;
}
