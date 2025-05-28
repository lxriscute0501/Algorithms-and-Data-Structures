#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, cnt=1;
    cin>>n;
    int a[n+1], dp[n+1];
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        dp[i] = 0;
    }
    
    int k=1;
    for (int i=2; i<=n; i++)
    {
        if (a[i] > a[k]+1) {
            cnt++;
            k = i;
        }
    }
    
    cout<<cnt<<'\n';
    return;
}

int main()
{
    int T;
    cin>>T;
    while (T--) {
        solve();
    }
    return 0;
}
