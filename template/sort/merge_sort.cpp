#include <iostream>
#include <algorithm>
using namespace std;

void merge(int* a, int low, int mid, int hight)
{
    int* b = new int [hight - low + 2];
    int i = low, j = mid + 1, k = 1;
    while (i <= mid and j <= hight)
    {
        if (a[i] <= a[j]) {
            b[k] = a[i];
            k ++; i ++;
        }
        else {
            b[k] = a[j];
            k ++; j ++;
        }
    }
    
    while (i <= mid)
    {
        b[k] = a[i];
        k ++; i ++;
    }
    while (j <= hight)
    {
        b[k] = a[j];
        k ++; j ++;
    }
    
    k = 0;
    for (int i = low; i <= hight; i++)
    {
        k ++;
        a[i] = b[k];
    }
    
    delete[] b;
}

void mergesort(int* a, int low, int hight)
{
    if (low < hight)
    {
        int mid = (low + hight) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, hight);
        merge(a, low, mid, hight);
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    mergesort(a, 1, n);
    
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
