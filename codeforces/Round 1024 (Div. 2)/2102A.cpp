
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m, p, q;
        cin >> n >> m >> p >> q;
        if (n % p == 0 and m != q * n / p) cout << "NO" << '\n'; else cout << "YES" << '\n';
    }

    return 0;
}
