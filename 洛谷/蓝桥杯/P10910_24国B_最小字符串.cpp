#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
char a[100001], b[100001];
int t1, t2;

int main()
{
    cin>>n>>m>>a>>b;
    sort(b, b + m);
    for (int i = 1; i <= n + m; i++)
    {
        if (t1 == n) cout << b[t2 ++ ];
        else if (t2 == m) cout << a[t1++];
        else cout << (a[t1] <= b[t2] ? a[t1++] : b[t2++]);
    }
    return 0;
}
