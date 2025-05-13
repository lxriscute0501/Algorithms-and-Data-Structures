#include <iostream>
#include <algorithm>
#include <climits>

# define int long long
using namespace std;

bool check(int* a, int* col, int n, int m, int mid) {
    int cnt = 0;
    for (int i=1; i<=n; i++)
    {
        if (a[i] < mid) cnt += mid - a[i];
    }
    return cnt <= m;
}

void merge(int* a, int* col, int low, int mid, int hight)
{
    int* b = new int [hight - low + 2];
    int* c = new int [hight - low + 2];
    int i = low, j = mid + 1, k = 1;
    while (i <= mid and j <= hight)
    {
        if (a[i] <= a[j]) {
            b[k] = a[i];
            c[k] = col[i];
            k ++; i ++;
        }
        else {
            b[k] = a[j];
            c[k] = col[j];
            k ++; j ++;
        }
    }
    
    while (i <= mid)
    {
        b[k] = a[i];
        c[k] = col[i];
        k ++; i ++;
    }
    while (j <= hight)
    {
        b[k] = a[j];
        c[k] = col[j];
        k ++; j ++;
    }
    
    k = 0;
    for (int i = low; i <= hight; i++)
    {
        k ++;
        a[i] = b[k];
        col[i] = c[k];
    }
    
    delete[] b;
    delete[] c;
}

void mergesort(int* a, int* col, int low, int hight)
{
    if (low < hight)
    {
        int mid = (low + hight) / 2;
        mergesort(a, col, low, mid);
        mergesort(a, col, mid + 1, hight);
        merge(a, col, low, mid, hight);
    }
}

signed main()
{
    int n,m;
    int a[200001], col[200001];
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<=n; i++)
        cin>>col[i];
    
    mergesort(a,col,1,n);
    int l = a[1], r = INT_MAX, mid, ans=0;
    for (int i=1; i<=n; i++)
        r = min(r, a[i]+col[i]);
    
    while (l <= r) {
        mid = (l + r) / 2;
        if (check(a, col, n, m, mid)) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    
    cout<<ans;
    return 0;
}