# 最大连续1的个数

## 题目描述
给定一个二进制数组， 计算其中最大连续 1 的个数。

#### 示例：
> 输入：[1,1,0,1,1,1]
> 输出：3
> 解释：开头的两位和最后的三位都是连续 1 ，所以最大连续 1 的个数是 3.

#### 提示：
> 输入的数组只包含 0 和 1 。
> 输入数组的长度是正整数，且不超过 10,000。


## 解析
### 方法1：暴力计算
- 遍历数组，计算1的个数，遇到0时进行记录


## 代码实现
### 方法1：暴力计算
#### CPP
```C++
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ret = 0;
        int zero_count = 0;
        for (int v : nums)
        {
            if (v)
            {
                zero_count++;
            }
            else
            {
                ret = zero_count > ret ? zero_count : ret;
                zero_count = 0;
            }
        }
        ret = zero_count > ret ? zero_count : ret;
        return ret;
    }
};
```