# 拥有最多糖果的孩子

## 题目描述
实现int sqrt(int x)函数。

计算并返回x的平方根，其中x是非负整数。

由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

#### 示例 1:
```
输入: 4
输出: 2
```
#### 示例 2:
```
输入: 8
输出: 2
说明: 8 的平方根是 2.82842..., 
     由于返回类型是整数，小数部分将被舍去。
```

## 代码实现
#### Python3
```python
class Solution:
    def mySqrt(self, x: int) -> int:
        if x == 0: return 0
        ans = int(math.exp(0.5 * math.log(x)))
        return ans + 1 if (ans + 1) ** 2 <= x else ans
```