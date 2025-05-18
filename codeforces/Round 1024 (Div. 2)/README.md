# Round 1024 (Div. 2)

A-250 B−500 C−1000 D−1750 E−2500 F−3000

## A. (2102A) Dinner Time

[Description](https://codeforces.com/problemset/problem/2102/A)

**Analysis:**

考虑不合法的情况。发现只有当$n$能被$p$整除，且$n$个数总和不等于想要构造出的$\frac{nq}{p}$时，才无法构造。

**Code:**
```cpp
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, m, p, q;
        cin >> n >> m >> p >> q;
        if (n % p == 0 and m != q * n / p) cout << "NO" << '\n'; else cout << "YES" << '\n';
    }
    return 0;
}

```

<br>

## B. (2102B) The Picky Cat

[Description](https://codeforces.com/problemset/problem/2102/B)

**Analysis:**

根据题意，原本数的正负对结果没有影响，为便于分析我们可都取绝对值。

考虑不合法的情况。当比$a[1]$大的数小于*应当大于中位数的个数*时，无论怎么取正负，$a[1]$都无法到达中间位置。

**Code:**
```cpp
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n + 1];
        for (int i=1; i<=n; i++)
        {
            cin >> a[i];
            if (a[i] < 0) a[i] = -a[i];
        }
        
        int num = (n+1)/2, cnt = 0;
        for (int i=2; i<=n; i++)
            if (a[i] > a[1]) cnt ++;
        if (cnt < num-1) cout << "NO" << '\n'; else cout << "YES" << '\n';
    }
    return 0;
}
```

<br>

## C. (2101A) Mex in the Grid

[Description](https://codeforces.com/problemset/problem/2101/A)

**Analysis:** 

为了让最小缺失的数最大，我们应该让较小的数尽量多次在*subgrid*中。只要确定了左上与右下角，我们就确定了一个*subgrid*。因此，对于一个方块，其左上角的点个数 乘以 右下角的点个数，即为它被选到的次数。

因为两数和相等时，差越小乘积越大，因此可以感觉到越靠近中间选到的次数越大。所以，因当将越小的数放在越中间。直觉告诉我们从中央按螺旋向外便利是可行的。

**Code:**
```cpp

```

<br>

## D. (2101B) Quartet Swapping

[Description](https://codeforces.com/problemset/problem/2101/B)

**Analysis:**

