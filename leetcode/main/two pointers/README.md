# Two Pointers 双指针

<br>

## 75. 颜色分类

[Description](https://leetcode.cn/problems/sort-colors/description/)

### Analysis

仅在**进阶**条件约束下分析。

**方法一：单指针**

两次遍历。第一次将$0$都移到前面，第二次将$1$都移到$0$的后面，剩下的即为$2$。

单指针$ptr$代表头部范围，于是：$i$从左到右便利，若 $nums[i]==0$，则 $swap(nums[i], nums[ptr])$，同时 $ptr+1$ 即可。$nums[i]==1$ 同理。

时间复杂度：$O(n)$\
空间复杂度：$O(1)$

**Code**
```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size(), ptr = 0;
        for (int i = 0; i < n; i++) 
        {
            if (nums[i] == 0) {
                swap(nums[i], nums[ptr]);
                ptr++;
            }
        }

        for (int i = ptr; i < n; i++) {
            if (nums[i] == 1) {
                swap(nums[i], nums[ptr]);
                ptr++;
            }
        }
    }
};
```

<br>

**方法二：双指针**

一次遍历。$p_0$代表交换$0$，$p_1$代表交换$1$，因为$0$在$1$之前，因此 $nums[i]==1$ 时，$p_1$后移；$nums[i]==0$ 时，$p_0$ 与 $p_1$ 均后移。但当 $p_0<p_1$ 时，交换会导致将$1$交换出去，因此必须再和 $nums[p_1]$ 交换一次，并将 $p_1$ 也后移。

时间复杂度：$O(n)$\
空间复杂度：$O(1)$

**Code**
```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int p0 = 0, p1 = 0;
        for (int i = 0; i < n; i++) 
        {
            if (nums[i] == 1) {
                swap(nums[i], nums[p1]);
                p1++;
            } else if (nums[i] == 0) {
                swap(nums[i], nums[p0]);
                if (p0 < p1) swap(nums[i], nums[p1]);
                p0++; p1++;
            }
        }
    }
};
```

