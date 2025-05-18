#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        cout << "digit" << endl;
        int x;
        cin >> x;

        cout << "digit" << endl;
        cin >> x;

        for (int i = 8; i >= 1; i /= 2)
        {
            cout << "add " << -i << endl;
            cin >> x;
        }

        cout << "add " << n - 1 << endl;
        cin >> x;

        cout << "!" << endl;
        cin >> x;
        assert(x == 1);
    }
}
