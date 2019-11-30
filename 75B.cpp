/*
Facetook Priority Wall
https://codeforces.com/problemset/problem/75/B
Solved by: Mohammad Shehab
codeforces handle : MShv97
*/
#include<bits/stdc++.h>

using namespace std;

map<string,int> mp;
void printAns(vector<string> v)
{
    sort(v.begin(),v.end());
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<endl;
}
int main()
{
    string name;
    cin>>name;
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        string x,pf,trash,y,trash2;
        cin>>x>>pf;
        if(pf=="likes")
        {
            cin>>y;
            cin>>trash2;
        }
        else
        {
            cin>>trash;
            cin>>y;
            cin>>trash2;
        }
        int score=0;
        if(pf=="posted")
            score+=15;
        else if(pf=="commented")
            score+=10;
        else
            score+=5;
        y.pop_back();
        y.pop_back();
        if(x==name || y==name)
        {
            mp[x]+=score;
            mp[y]+=score;
        }
        else
        {
            mp[x]+=0;
            mp[y]+=0;
        }
    }
    set<int> st;
    for(auto m : mp)
        st.insert(m.second);
    vector<vector<string>> ans;
    for(auto i : st)
    {
        vector<string> v;
        for(auto m : mp)
        {
            if(m.second == i && m.first !=name)
                v.push_back(m.first);
        }
        ans.push_back(v);
    }
    reverse(ans.begin(),ans.end());
    for(auto i : ans)
        printAns(i);

    return 0;
    
}
