# 6 和 9 组成的最大数字

## 题目描述
给你一个仅由数字 6 和 9 组成的正整数 num。

你最多只能翻转一位数字，将 6 变成 9，或者把 9 变成 6 。

请返回你可以得到的最大数字。

#### 示例 1:
```
输入：num = 9669
输出：9969
解释：
改变第一位数字可以得到 6669 。
改变第二位数字可以得到 9969 。
改变第三位数字可以得到 9699 。
改变第四位数字可以得到 9666 。
其中最大的数字是 9969 。
```
#### 示例 2:
```
输入：num = 9996
输出：9999
解释：将最后一位从 6 变到 9，其结果 9999 是最大的数。
```
#### 示例 3:
```
输入：num = 9999
输出：9999
解释：无需改变就已经是最大的数字了。
```
提示：

- 1 <= num <= 10^4
- num 每一位上的数字都是 6 或者 9 。

## 代码实现
#### Python3
```python
class Solution:
    def maximum69Number (self, num: int) -> int:
        return int(str(num).replace("6", "9", 1))   # 修改最高位的即可
```
#### CPP
```C++
class Solution {
public:
    int maximum69Number (int num) {
        string num_str = to_string(num);
        for (int i = 0 ; i < num_str.size(); i++)
        {
            if (num_str[i] == '6')
            {
                num_str[i] = '9';
                break;
            }
        }
        return stoi(num_str);
    }
};
```