//1400
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int d[n+1];
    for (int i=1; i<=n; i++)
        cin >> d[i];
    
    int l[n+1], r[n+1];
    for (int i=1; i<=n; i++)
        cin >> l[i] >> r[i];
    
    int left = 0;
    vector<int> res;
    for (int i=1; i<=n; i++)
    {
        if (d[i] == -1) {
            res.push_back(i);
        } else {
            left += d[i];
        }
        
        while (left < l[i]) {
            if (res.empty()) {
                cout << -1 << '\n';
                return;
            }
            d[res.back()] = 1;
            left++;
            res.pop_back();
        }
        
        while (left + res.size() > r[i]) {
            if (res.empty()) {
                cout << -1 << '\n';
                return;
            }
            d[res.back()] = 0;
            res.pop_back();
        }
    }
    for (int i=1; i<=n; i++)
        cout << max(0, d[i]) << " ";
    cout << '\n';
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
