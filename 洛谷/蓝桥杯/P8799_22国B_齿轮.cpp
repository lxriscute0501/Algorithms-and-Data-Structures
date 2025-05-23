#include <iostream>
#include <algorithm>
using namespace std;

int n,q,k1,mp[300001],ans[300001],a[300001];

int main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    
    sort(a+1,a+n+1);
    
    for (int i = 1; i <= n; i++)
    {
        if (i > 1 and a[i] == a[i-1]) continue;
        for (int j = a[i]; j <= a[n]; j += a[i])
        {
            if (!mp[j]) continue;
            if (mp[j] == 1 and j == a[i]) continue;
            ans[j/a[i]] = 1;
        }
    }
    
    while (q--)
    {
        cin >> k1;
        if(ans[k1] == 1) printf("YES\n"); else printf("NO\n");
    }
    return 0;
}