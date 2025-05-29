#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n,m;
    long long a[100005];
    long long ans=1e12;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        long long x;
        cin>>x;
        a[i]=x*x;
    }
    sort(a+1,a+1+n);
    for (int i=1;i<=n-m+1;i++)
    {
        ans=min(ans,a[i+m-1]-a[i]);
    }
    cout<<ans;
    return 0;
}