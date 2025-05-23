#include<bits/stdc++.h>
using namespace std;

int d[10001],u[100001],v[100001];

int main()
{
    int n,m;
    long long ans=0;
    cin>>n>>m;
    
    memset(d,0,sizeof(d));
    
    for(int i=0; i<m; i++)
    {
        cin>>u[i]>>v[i];
        d[u[i]]++;
        d[v[i]]++;
    }
    
    for(int i=0; i<m; i++)
    {
        if(d[u[i]] > 1 and d[v[i]] > 1) ans += (d[u[i]]-1) * (d[v[i]]-1) * 2;
    }
    
    cout<<ans;
    return 0;
}