//1200
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        int cnt1 = 1, cnt2 = 1;
        int n1=n-max(a-1,n-a), n2=n;
        int m1=m, m2=m-max(b-1,m-b);
        
        while (n1 > 1) {
            n1 = (n1+1)/2;
            cnt1 ++;
        }
        while (m1 > 1) {
            m1 = (m1+1)/2;
            cnt1 ++;
        }
        while (n2 > 1) {
            n2 = (n2+1)/2;
            cnt2 ++;
        }
        while (m2 > 1) {
            m2 = (m2+1)/2;
            cnt2 ++;
        }
        cout << min(cnt1,cnt2) << '\n';
    }
    return 0;
}
