
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int a[n + 1];
        for (int i=1; i<=n; i++)
        {
            cin >> a[i];
            if (a[i] < 0) a[i] = -a[i];
        }
        
        int num = (n+1)/2, cnt = 0;
        for (int i=2; i<=n; i++)
            if (a[i] > a[1]) cnt ++;
        if (cnt < num-1) cout << "NO" << '\n'; else cout << "YES" << '\n';
    }

    return 0;
}
