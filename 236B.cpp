/*
Easy Number Challenge
https://codeforces.com/problemset/problem/236/B

Solved by: Mohammad Shehab
codeforces handle : MShv97
*/
#include<bits/stdc++.h>

using namespace std;

int memo[1000006];
int d(int n)
{
    if(memo[n]) return memo[n];
    int cnt = 0;
    for (int i = 1; i <= sqrt(n); i++)
        if (n % i == 0)
        {
            if (n / i == i)
                cnt++;
            else
                cnt+=2;
        }

    return memo[n]=cnt;
}
int mod = 1<<30;
int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int res=0;
    for(int i=1; i<=a; i++)
        for(int j=1; j<=b; j++)
            for(int k=1; k<=c; k++)
                res=(res+d(i*j*k))%mod;

    printf("%d",res);

    return 0;
}
