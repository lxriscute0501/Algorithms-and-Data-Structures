#include<bits/stdc++.h>
using namespace std;

bool isprime(int a)
{
    for(int i=2;i*i<=a;i++)
        if(a % i == 0) return false;
    return true;
}

int n,k;
int a[25];
bool vis[25];
long long ans=0;

void dfs(int m,int sum,int startx)
{
    if(m == k)
    {
        if(isprime(sum)) ans++;
        return;
    }
    for(int i=startx;i<n;i++)
    {
        if(vis[i]) continue;
        vis[i] = true;
        dfs(m+1,sum+a[i],i+1);
        vis[i] = false;
    }
    return;
}
int main()
{
    cin>> n >> k;
    for(int i=0;i<n;i++)
        cin>> a[i];
    dfs(0,0,0);
    cout<< ans;
    return 0;
}