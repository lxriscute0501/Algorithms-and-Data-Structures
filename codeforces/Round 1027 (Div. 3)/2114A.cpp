//800
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int num = 0;
    string s;
    cin>>s;
    for (int i=0; i<s.length(); i++)
    {
        int x=s[i]-'0';
        num += x * pow(10, 3-i);
    }
    for (int i=0; i<100; i++)
    {
        if (i * i == num) {
            cout<<0<<" "<<i<<'\n';
            return;
        }
    }
    cout<<-1<<'\n';
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
