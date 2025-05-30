#include <iostream>
using namespace std;

int main()
{
    int n,m;
    int dp[30001];
    int v[26], p[26];
    cin>>n>>m;
    for (int i=1; i<=m; i++)
        cin>>v[i]>>p[i];
    
    for (int i=0; i<=n; i++)
        dp[i] = 0;
    
    for (int i=1; i<=m; i++)
    {
        for (int j=n; j>=v[i]; j--)
            dp[j] = max(dp[j], dp[j - v[i]] + v[i] * p[i]);
    }
    cout<<dp[n];
    return 0;
}
