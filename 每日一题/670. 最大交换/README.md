# 670. 最大交换

## 题目描述
给定一个非负整数，你至多可以交换一次数字中的任意两位。返回你能得到的最大值。

#### 示例 1：
```
输入: 2736
输出: 7236
解释: 交换数字2和数字7。
```

##### 示例 2：
````
输入: 9973
输出: 9973
解释: 不需要交换。
```

#### 注意：
- 给定数字的范围是 [0, 108]


## 代码实现
#### Python
```python
class Solution:
    def maximumSwap(self, num: int) -> int:
        res = num
        s = list(str(num))
        for i in range(len(s)):
            for j in range(i):
                s[i], s[j] = s[j], s[i]
                res = max(res, int(''.join(s)))
                s[i], s[j] = s[j], s[i]
        return res
```