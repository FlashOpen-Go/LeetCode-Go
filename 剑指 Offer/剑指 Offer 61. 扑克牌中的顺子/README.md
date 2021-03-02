# 剑指 Offer 61. 扑克牌中的顺子


## 题目描述
从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。A 不能视为 14。

```c
示例 1:
输入: [1,2,3,4,5]
输出: True

示例 2:
输入: [0,0,1,2,5]
输出: True
 
限制：
数组长度为 5 
数组的数取值为 [0, 13]
```


## 解析
#### 方法1：
- 首先对数组进行排序
- 然后找出第一个非零的位置
- 同时需要对数据进行检查，判断是否由重复数据
- 之后再将非零的最小值和最大值相减，判断插值是否再 5 以内即可



## 代码实现
#### 方法1
#### CPP
```C++
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int zerocount = 0;
        for(int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == 0)
            {
                zerocount++;
            }
            else if (nums[i] == nums[i + 1])
            {
                return false;
            }
        }
        return (nums[4] - nums[zerocount] < 5);
    }
};
```