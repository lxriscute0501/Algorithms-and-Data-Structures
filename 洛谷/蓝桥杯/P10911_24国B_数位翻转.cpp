#include <bits/stdc++.h>
using namespace std;

int n,m;
long long a[1001], b[1001];
long long dp[1001][1001][2];

int main()
{
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    
    for (int i=1; i<=n; i++)
    {
        long long x = a[i], cnt = 0, sum = 0;
        while (x > 0) {
            x /= 2;
            cnt ++;
        }
        x = a[i];
        while (x > 0) {
            sum += (x % 2) * pow(2, cnt-1);
            x /= 2;
            cnt --;
        }
        b[i] = sum - a[i];
    }
    
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            dp[i][j][0] = dp[i][j][1] = 0;
    
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1]);
            dp[i][j][1] = max(dp[i-1][j-1][0], dp[i-1][j][1]) + b[i];
        }
    }
    
    long long ans = 0;
    for (int i=1; i<=m; i++)
        ans = max(max(ans, dp[n][i][0]), dp[n][i][1]);
    for (int i=1; i<=n; i++)
        ans += a[i];
    cout<<ans;
    return 0;
}
