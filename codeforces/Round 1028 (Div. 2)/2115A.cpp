
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int compute_gcd(vector<int>& arr) {
    int current_gcd = arr[0];
    for (size_t i = 1; i < arr.size(); ++i) {
        current_gcd = gcd(current_gcd, arr[i]);
        if (current_gcd == 1) break;
    }
    return current_gcd;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        int total = compute_gcd(a), count_gcd = 0;
        for (int num : a)
        {
            if (num == total) count_gcd++;
        }

        if (count_gcd > 0) {
            cout << n - count_gcd << '\n';
        } else {
            vector<int> b(n);
            int max_b = 0;
            for (int i = 0; i < n; ++i)
            {
                b[i] = a[i] / total;
                if (b[i] > max_b) max_b = b[i];
            }

            vector<int> dp(max_b + 1, INT_MAX / 2);
            for (int i = 0; i < n; ++i)
            {
                for (int d = max_b; d >= 1; d--)
                {
                    if (dp[d] < INT_MAX / 2) {
                        int g_val = gcd(d, b[i]);
                        if (g_val <= max_b) {
                            if (dp[g_val] > dp[d] + 1) dp[g_val] = dp[d] + 1;
                        }
                    }
                }
                if (dp[b[i]] > 1) dp[b[i]] = 1;
            }

            cout << dp[1] + n - 2 << '\n';
        }
    }

    return 0;
}
