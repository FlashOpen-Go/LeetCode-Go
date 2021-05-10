# 和为零的N个唯一整数

## 题目描述
给你一个整数 n，请你返回 任意 一个由 n 个 各不相同 的整数组成的数组，并且这 n 个数相加和为 0 。

#### 示例 1:
```
输入：n = 5
输出：[-7,-1,1,3,4]
解释：这些数组也是正确的 [-5,-1,1,2,3]，[-3,-1,2,-2,4]。
```
#### 示例 2:
```
输入：n = 3
输出：[-1,0,1]
```
#### 示例 3:
```
输入：n = 1
输出：[0]
```
提示：

- 1 <= n <= 1000

## 代码实现
#### Python3
```python
class Solution:
    def sumZero(self, n: int) -> List[int]:
        if n != 2:
            res = [x for x in range(n-1)]
            res.append(-sum(res))
            return res
        else:
            return [-1,1]
```
#### CPP
```C++
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ret;
        for (int i = 0; i < n / 2; i++)
            {
                ret.push_back(i + 1);
                ret.push_back(-(i + 1));
            }
        if (n % 2 == 0)
        {
            return ret;
        }
        else
        {
            ret.push_back(0);
        }
        return ret;
    }
};
```