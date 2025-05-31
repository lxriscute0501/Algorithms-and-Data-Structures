//800
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        
        bool possible = true;
        for (int i = 0; i < n; ++i)
        {
            if (a[i] == 0) {
                if (i > 0 and a[i-1] == 0) {
                    possible = false;
                    break;
                }
                if (i < n-1 and a[i+1] == 0) {
                    possible = false;
                    break;
                }
            }
        }
        
        if (!possible) {
            cout << "YES" << endl;
        } else {
            bool allZero = true, all1 = true;
            for (int num : a) {
                if (num == 1) {
                    allZero = false;
                    break;
                }
            }
            for (int num : a) {
                if (num == 0) {
                    all1 = false;
                    break;
                }
            }
            if (allZero or all1) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}
