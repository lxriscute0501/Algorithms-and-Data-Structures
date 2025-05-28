#include <iostream>
using namespace std;

int n,m;
int a[100001];

bool check(int mid) {
    int cnt = m;
    for (int i=1; i<=n; i++)
    {
        if (a[i] - a[i-1] > mid) {
            cnt -= (a[i] - a[i-1] - 1) / mid;
        }
        if (cnt < -1) return false;
    }
    return cnt >= -1;
}

int main()
{
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    a[0] = 0;
    int l = 1, r = a[n], mid, ans = 0;
    while (l <= r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    cout<<ans;
    return 0;
}
