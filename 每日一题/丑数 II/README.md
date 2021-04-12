# 丑数 II

## 题目描述
给你一个整数 n ，请你找出并返回第 n 个 丑数 。

丑数 就是只包含质因数 2、3 和/或 5 的正整数。
 

#### 示例 1：
> 输入：n = 10
> 输出：12
> 解释：[1, 2, 3, 4, 5, 6, 8, 9, 10, 12] 是由前 10 个丑数组成的序列。

#### 示例 2：
> 输入：n = 1
> 输出：1
> 解释：1 通常被视为丑数。


##### 提示：
> 1 <= n <= 1690


## 解析


## 代码实现
### 方法1：动态规划
#### CPP
```C++
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> array(n);
        array[0] = 1;
        int dp_2 = 0;
        int dp_3 = 0;
        int dp_5 = 0;
        for (int i = 1 ; i < n; ++i)
        {
            array[i] = min(min(array[dp_2] * 2, array[dp_3] * 3), array[dp_5] * 5);
            if ((array[dp_2] * 2) == array[i])
            {
                ++dp_2;
            }
            if (array[dp_3] * 3 == array[i])
            {
                ++dp_3;
            }
            if (array[dp_5] * 5 == array[i])
            {
                ++dp_5;
            }
        }
        return array[n - 1];
    }
};
```