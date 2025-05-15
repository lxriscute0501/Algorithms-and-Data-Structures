//1300
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        long long n, x;
        cin >> n >> x;
        
        if (n == 1) {
            cout << (x != 0 ? x : -1) << '\n';
            continue;
        } else {
            if (x == 0) {
                if (n % 2 == 0) {
                    cout << n << '\n';
                    continue;
                } else {
                    cout << n + 3 << '\n';
                    continue;
                }
            } else if (x == 1) {
                if (n % 2 == 0) {
                    cout << n + 3 << '\n';
                    continue;
                } else {
                    cout << n << '\n';
                    continue;
                }
            }
        }

        long long temp = x, cnt = 0;
        while (temp > 0) {
            cnt += temp % 2;
            temp = temp >> 1;
        }
        
        if (n >= cnt + 1) {
            if ((n-cnt) % 2 == 0) cout << n-cnt+x << '\n';
            else cout << n-cnt+x+1 << '\n';
        } else cout << x << '\n';
    }
    return 0;
}
