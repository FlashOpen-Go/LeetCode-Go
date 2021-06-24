# 两数之和 II - 输入有序数组

## 题目描述
给定一个已按照 升序排列  的整数数组 numbers ，请你从数组中找出两个数满足相加之和等于目标数 target 。

函数应该以长度为 2 的整数数组的形式返回这两个数的下标值。numbers 的下标 从 1 开始计数 ，所以答案数组应当满足 1 <= answer[0] < answer[1] <= numbers.length 。

你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。

 
#### 示例 1：
> 输入：numbers = [2,7,11,15], target = 9
> 输出：[1,2]
> 解释：2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。

#### 示例 2：
> 输入：numbers = [2,3,4], target = 6
> 输出：[1,3]

#### 示例 3：
> 输入：numbers = [-1,0], target = -1
> 输出：[1,2]
 

#### 提示：
- 2 <= numbers.length <= 3 * 104
- -1000 <= numbers[i] <= 1000
- numbers 按 递增顺序 排列
- -1000 <= target <= 1000
- 仅存在一个有效答案


## 解析
### 方法1：双指针
首先数组是递增的，定义两个指针分别指向数组的开头和结尾，计算两个指针的位置元素和，如果计算和大于给定的target值，那么末尾指针则需要向左移动，获取一个更小的值。反之相同。


## 代码实现
### 方法1：双指针
#### CPP
```C++
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ret(2, 0);
        int left = 0;
        int right = numbers.size() - 1;
        while(right > left)
        {
            if (numbers[left] + numbers[right] == target)
            {
                ret[0] = left + 1;
                ret[1] = right + 1;
                break;
            }
            else if (numbers[left] + numbers[right] > target)
            {
                right--;
            }
            else
            {
                left++;
            }
        }
        return ret;
    }
};
```