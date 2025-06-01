
#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll MOD = 998244353;

ll binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % MOD;
    a = (a * a) % MOD;
    b >>= 1;
  }
  return res % MOD;
}

void solve() {
    int n;
    cin>>n;
    ll p[n+1], q[n+1], r[n+1], sup[n+1], suq[n+1], lop[n+1], loq[n+1];
    
    sup[0] = -1; suq[0] = -1;
    lop[0] = 0; loq[0] = 0;
    for (int i=1; i<=n; i++)
    {
        cin>>p[i];
        if (p[i] > sup[i-1]) {
            sup[i] = p[i];
            lop[i] = i;
        } else {
            sup[i] = sup[i-1];
            lop[i] = lop[i-1];
        }
        
    }
    for (int i=1; i<=n; i++)
    {
        cin>>q[i];
        if (q[i] > suq[i-1]) {
            suq[i] = q[i];
            loq[i] = i;
        } else {
            suq[i] = suq[i-1];
            loq[i] = loq[i-1];
        }
    }
    
    for (int i=1; i<=n; i++)
    {
        if (sup[i] > suq[i] or (sup[i] == suq[i] and (q[i+1-lop[i]] > p[i+1-loq[i]]))) {
            r[i] = (binpow(2, sup[i]) + binpow(2, q[i+1-lop[i]])) % MOD;
        } else {
            r[i] = (binpow(2, suq[i]) + binpow(2, p[i+1-loq[i]])) % MOD;
        }
    }
    
    for (int i=1; i<=n; i++)
        cout<<r[i]<<" ";
    cout<<'\n';
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
