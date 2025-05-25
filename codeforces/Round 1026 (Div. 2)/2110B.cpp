#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin>>s;
    int l=0, r=0;
    for (int i=0; i<s.length()-1; i++)
    {
        if (s[i]=='(') l++; else r++;
        if (l == r) {
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
    return;
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
