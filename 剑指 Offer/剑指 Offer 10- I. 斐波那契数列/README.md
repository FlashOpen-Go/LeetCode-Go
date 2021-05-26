# 剑指 Offer 10- I. 斐波那契数列

## 题目描述
写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项（即 F(N)）。斐波那契数列的定义如下：
```c
F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
```
斐波那契数列由 0 和 1 开始，之后的斐波那契数就是由之前的两数相加而得出。
答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

```c
示例 1：
输入：n = 2
输出：1

示例 2：
输入：n = 5
输出：5
 
提示：
0 <= n <= 100
```


## 解析
#### 方法1
- 首先考虑使用递归来实现，重复调用该函数
- 递归退出的条件为 n 小于 2 时，这时值为确定值

#### 方法2
- 按照公式进行计算
- f(n) = f(n - 1) + f(n - 2)

## 代码实现
```C++
class Solution {
public:
    int fib(int n) {
        if (n < 2)
            return n;
        int ret = 0;
        int f_0 = 0;
        int f_1 = 1;
        for (int i = 1 ; i < n; i++)
        {
            ret = f_0 + f_1;
            ret %= 1000000007;
            f_0 = f_1;
            f_1 = ret;
        }
        return ret;
    }
};
```

```C++
class Solution {
public:
    int fib(int n) {
        if (n < 2)
            return n;
        return ((fib(n - 1) + fib(n - 2)) % 1000000007);
    }
};
```
```Java
class Solution {
    public int fib(int n) {
        if(n<2) return n;
		//初始化fib（0）和fib（1）
		int pre = 0,next = 1;
		for(int i=2;i<=n;i++) {
			int temp = (pre+next)%1000000007;
			//把next重新设为pre，开始累加
			pre = next;
			//把当前fib（n）设为next
			next = temp;
		}
		//返回next，即fib（n）
		return next;
    }
}
```
#### Python3
```python
class Solution:
    def fib(self, n: int) -> int:
        a, b = 0, 1
        for _ in range(n):      # 单下划线代表一个临时值，作为一个占位符变量
            a, b = b, a + b
        return a % 1000000007
```