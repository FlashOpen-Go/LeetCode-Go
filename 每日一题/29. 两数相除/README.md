# 29. 两数相除

## 题目描述
给定两个整数，被除数dividend和除数divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。

返回被除数dividend除以除数divisor得到的商。

整数除法的结果应当截去（truncate）其小数部分，例如：truncate(8.345) = 8 以及 truncate(-2.7335) = -2

### 示例 1：
```
输入: dividend = 10, divisor = 3
输出: 3
解释: 10/3 = truncate(3.33333..) = truncate(3) = 3
```
### 示例 2：
```
输入: dividend = 7, divisor = -3
输出: -2
解释: 7/-3 = truncate(-2.33333..) = -2
```

### 提示：

 - 被除数和除数均为 32 位有符号整数。 
 - 除数不为0。 
 - 假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−2^31, 2^31 − 1]。本题中，如果除法结果溢出，则返回 2^31− 1。
 
### 解析：
暴力解法：
 - 时间复杂度O(N),会超时
 - 空间复杂度O(1)

## 代码实现
### Python3
```python
class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        int_max = 2**31 - 1
        int_min = -2**31
        if dividend < 0 and divisor < 0:
            sign = 1
        elif dividend > 0 and divisor > 0:
            sign = 1
        else:
            sign = -1
        if dividend == int_max:
            if divisor == 1:
                return int_max
            if divisor == -1:
                return -1*int_max
        if dividend == int_min:
            if divisor == 1:
                return int_min
            if divisor == -1:
                return 2**31-1
        if dividend == 0:
            return 0
        else:
            i = 0
            dividend = abs(dividend)
            divisor = abs(divisor)
            while dividend >= divisor:
                i += 1
                dividend -= divisor
            return i*sign
```