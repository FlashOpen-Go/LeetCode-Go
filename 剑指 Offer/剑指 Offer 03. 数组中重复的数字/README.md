# 剑指 Offer 03. 数组中重复的数字

## 题目描述
找出数组中重复的数字。
在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

```c
示例 1：
输入：
[2, 3, 1, 0, 2, 5, 3]
输出：2 或 3 
 
限制：
2 <= n <= 100000
```

## 解析
- 读题可以得知如果再没有重复数字的情况下对数组进行排序，那么排序之后的数组下标和对应存储的值应该是相同的。
- 因此，可以使用该方法来进行判断。
- 首先对数组进行排序，之后遍历数组，如果出现下标和存储值不一致，则将存储值最为下标去访问该位置的数值，判断该数值和当前值是否相同。

## 代码实现
#### CPP
```C++
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());     //排序
        int count = nums.size();
        for (int i = 0 ; i < count; i++)    // 遍历数组
        {
            if (i != nums[i])   // 下标与对应值不一致
            {
                if (nums[nums[i]] == nums[i])   // 查看存储值对应的下标位置，值是否相同
                {
                    return nums[i];
                }
            }
        }
        return -1;
    }
};
```
#### Java
```Java
class Solution {
    public int findRepeatNumber(int[] nums) {
        int[] nnn = new int[100000];
		for(int i=0;i<nums.length;i++) {
			//给nnn[nums[i]]值加1
			nnn[nums[i]]  = nnn[nums[i]]+1;
			//如果nnn[nums[i]]大于1，说明nums[i]出现不止一次，返回nums[i]
			if(nnn[nums[i]]>1) {
				return nums[i];
			}
		}
		return 0;
    }
};
```
#### Python3
```python
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        dic = set()
        for i in nums:
            if i in dic: return i
            dic.add(i)
        return -1
```