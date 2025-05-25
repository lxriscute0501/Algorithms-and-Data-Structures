//1100
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while (T--) 
    {
        int n, k;
        cin>>n>>k;
        
        int a[n+1];
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        
        sort(a+1,a+1+n);
        
        if (a[n]-a[1] > k+1 or (a[n]-a[1] == k+1 and a[n] == a[n-1])) {
            cout<<"Jerry\n";
            continue;
        }
        
        long long sum = 0;
        for (int i = 1; i <= n; i++)
            sum += (long long)a[i];
        if (sum % 2 == 0) {
            cout<<"Jerry\n";
            continue;
        } else {
            cout<<"Tom\n";
            continue;
        }
        
    }
    return 0;
}
