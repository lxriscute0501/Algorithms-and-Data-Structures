#include <iostream>
using namespace std;

int main()
{
    int n,vol;
    int dp[20001];
    int v[31];
    
    cin>>vol>>n;
    for (int i=1; i<=n; i++)
        cin>>v[i];
    
    for (int i=0; i<=vol; i++)
        dp[i] = 0;
    
    for (int i=1; i<=n; i++)
    {
        for (int j=vol; j>=v[i]; j--)
            dp[j] = max(dp[j], dp[j - v[i]] + v[i]);
    }
    cout << vol - dp[vol];
    return 0;
}
