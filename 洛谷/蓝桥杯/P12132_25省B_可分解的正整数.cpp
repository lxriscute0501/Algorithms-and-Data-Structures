#include <iostream>
using namespace std;

int main()
{
    int n;
    int ans=0;
    int a[100005];
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=n;i++)
    {
        if (a[i]>1) ans++;
    }
    cout<<ans;
    return 0;
}