//900
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n,k;
    int n1=0,n0=0;
    string s;
    cin>>n>>k;
    cin>>s;
    for (int i=0; i<n; i++)
    {
        if (s[i]=='1') n1++; else n0++;
    }
    if (n1>=n/2-k and n1<=n/2+k and (n1-n/2-k)%2==0) cout<<"YES"<<'\n'; else cout<<"NO"<<'\n';
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

