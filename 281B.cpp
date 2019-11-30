/*
Nearest Fraction
https://codeforces.com/problemset/problem/281/B
Solved by: Mohammad Shehab
codeforces handle : MShv97
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long x,y,n;
    scanf("%lld%lld%lld",&x,&y,&n);
    double mn = 1e7;
    int a,b;
    long double z =x/(y*1.0);
    for(int i=1; i<=n; i++)
    {
        long long dj[3];
        dj[1]=(x*i)/y;
        dj[0]=dj[1]-1;
        dj[2]=dj[1]+1;
        for(int j=0; j<3; j++)
        {
            long double zz =z;
            zz-=dj[j]/(i*1.0);
            if(abs(zz)<mn)
            {
                mn=abs(zz);
                a=dj[j];
                b=i;
            }
        }
    }


    printf("%d/%d",a,b);

    return 0;
}
