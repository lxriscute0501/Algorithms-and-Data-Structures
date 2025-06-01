
#include <iostream>
using namespace std;

void solve() {
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if (min(a,c) < min(b,d)) cout<<"Flower\n"; else cout<<"Gellyfish\n";
    return;
}

int main()
{
    int T;
    cin>>T;
    while (T--) {
        solve();
    }
    return 0;
}
