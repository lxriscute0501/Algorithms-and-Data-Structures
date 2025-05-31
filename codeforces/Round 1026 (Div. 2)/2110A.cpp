//800
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    int a[51];
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    sort(a+1, a+1+n);
    
    if ((a[1] + a[n]) % 2 == 0) {
        cout << 0 << '\n';
        return;
    } else {
        int k1=2, k2=n-1;
        while (k1 <= n and (a[k1]-a[1]) % 2 == 0) k1++;
        while (k2 >= 1 and (a[n]-a[k2]) % 2 == 0) k2--;
        cout << min(k1-1,n-k2) << '\n';
    }
    
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
