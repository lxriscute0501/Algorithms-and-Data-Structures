//800
#include <bits/stdc++.h>
using namespace std;

int my_gcd(int a, int b) {
    return b == 0 ? a : my_gcd(b, a % b);
}

int compute_gcd(const vector<int>& v) {
    int gcd_val = v[0];
    for (int num : v) 
    {
        gcd_val = my_gcd(gcd_val, num);
        if (gcd_val == 1) break;
    }
    return gcd_val;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    bool all_same = true;
    for (int i = 1; i < n; ++i) {
        if (a[i] != a[0]) {
            all_same = false;
            break;
        }
    }
    if (all_same) {
        cout << "NO\n";
        return;
    }

    for (int i = 0; i < n; i++)
    {
        vector<int> B = {a[i]};
        vector<int> C;

        for (int j = 0; j < n; j++)
        {
            if (j != i) {
                C.push_back(a[j]);
            }
        }

        int gcd_B = compute_gcd(B);
        int gcd_C = compute_gcd(C);
        if (gcd_B != gcd_C) {
            cout << "YES\n";
            for (int j = 0; j < n; ++j) 
            {
                if (j == i) cout << "1 "; else cout << "2 ";
            }
            cout << '\n';
            return;
        }
    }

    cout << "NO\n";
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
