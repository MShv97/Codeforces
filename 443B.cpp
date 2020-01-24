/*
Kolya and Tandem Repeat
https://codeforces.com/problemset/problem/443/B

Solved by: Mohammad Shehab
codeforces handle : MShv97
*/

#include<bits/stdc++.h>

using namespace std;

int main()
{
    char s[404];
    int k;
    scanf("%s%d",s,&k);
    int n = strlen(s);
    for(int i=0; i<k; i++)
        s[i+n] = '?';
    s[n+k] = '\0';
    int res =0;
    for(int i=2; i<=n+k; i+=2)
        for(int start = 0; start <= n+k-i; start++)
        {
            bool f=1;
            for(int l = start,r=start+i/2; l<start+i/2 && f; l++,r++)
            {
                if(s[l] == '?' || s[r] == '?') continue;
                if(s[l]!= s[r]) f=0;
            }
            if(f) res = max(res,i);
        }

    printf("%d",res);

    return 0;
}
