# 剑指 Offer 64. 求1+2+…+n

## 题目描述
求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

```c
示例 1：
输入: n = 3
输出: 6

示例 2：
输入: n = 9
输出: 45
 
限制：
1 <= n <= 10000
```

## 解析
#### 方法1：
- 首先考虑使用递归来进行实现，递归结束条件为 n = 0
- 由于不能使用 if 等条件语句，因此需要使用其他运算符来替代
- a && b, 此时 a 和 b 可以是数字也可以为表达式，如果 a 为真，那么会继续执行 b ，如果 a 为假， 则不会执行 b，因此可以利用该条件来作为递归结束的条件。

## 代码实现
#### CPP
```C++
class Solution {
public:
    int sumNums(int n) {
        int sum = n;
        n && (sum += sumNums(n-1));
        return sum;
        // if (n == 0)
        //     return 0;
        // int sum = n;
        // sum += sumNums(n - 1);
        // return sum;
    }
};
```
#### Java
```Java
class Solution {
    public int sumNums(int n) {
        if(n==1) {
			return 1;
		}
		return n+sumNums(n-1);
    }
};
```
#### Python
```python
class Solution:
    def __init__(self):
        self.res = 0
    def sumNums(self, n: int) -> int:
        n > 1 and self.sumNums(n - 1)
        self.res += n
        return self.res
```