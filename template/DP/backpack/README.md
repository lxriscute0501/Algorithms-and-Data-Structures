# Backpack Problem 背包问题

<br>

## 01背包

物品只有选或不选之分。设有$n$件物品，允许的总容量为$m$，每件物品的容量为$v[i]$，价值为$w[i]$。用$dp[i][j]$表示前$i$件物品，在选择的总容量不超过$j$时的最大价值。可列出数学表达式为：
```math
dp[i][j] = \begin{cases} dp[i-1][j], & \text{not choose } i \\
dp[i-1][j-v[i]]+w[i], & \text{choose } i \end{cases}
```

当然，$j-v[i]$必须非负，故程序为：
```cpp
for (int i = 1; i <= n; i++)
{
    for (int j = v[i]; j <= m; j++)
    {
        dp[i][j] = max(dp[i-1][j], dp[i-1][j-v[i]] + w[i]);
    }
}
return dp[n][m];
```

时间复杂度：$O(nm)$

我们发现$dp[i][j]$只与上一层状态，即$dp[i-1][j]$有关，因此可以优化为一维：
```cpp
for (int i = 1; i <= n; i++)
{
    for (int j = m; j >= v[i]; j--)
    {
        dp[j] = max(dp[j], dp[j-v[i]] + w[i]);
    }
}
return dp[m];
```

时间复杂度：$O(nm)$

<br>

## 完全背包



<br>

## 多重背包

