# 寻找旋转排序数组中的最小值

## 题目描述
已知一个长度为 n 的数组，预先按照升序排列，经由 1 到 n 次 旋转 后，得到输入数组。例如，原数组 nums = [0,1,2,4,5,6,7] 在变化后可能得到：
若旋转 4 次，则可以得到 [4,5,6,7,0,1,2]
若旋转 7 次，则可以得到 [0,1,2,4,5,6,7]
注意，数组 [a[0], a[1], a[2], ..., a[n-1]] 旋转一次 的结果为数组 [a[n-1], a[0], a[1], a[2], ..., a[n-2]] 。

给你一个元素值 互不相同 的数组 nums ，它原来是一个升序排列的数组，并按上述情形进行了多次旋转。请你找出并返回数组中的 最小元素 。 

#### 示例 1：
```C
输入：nums = [3,4,5,1,2]
输出：1
解释：原数组为 [1,2,3,4,5] ，旋转 3 次得到输入数组。
```

#### 示例 2：
```c
输入：nums = [4,5,6,7,0,1,2]
输出：0
解释：原数组为 [0,1,2,4,5,6,7] ，旋转 4 次得到输入数组。
```

#### 示例 3：
```c
输入：nums = [11,13,15,17]
输出：11
解释：原数组为 [11,13,15,17] ，旋转 4 次得到输入数组。
```

##### 提示
> n == nums.length
> 1 <= n <= 5000
> -5000 <= nums[i] <= 5000
> nums 中的所有整数 互不相同
> nums 原来是一个升序排序的数组，并进行了 1 至 n 次旋转


## 解析
### 方法1：暴力破解
- 直接记录遍历整个数组，记录最小是

### 方法2：二分查找
- 左侧值为 left, 中间值为 mid， 右侧值为 right
- 那么会有下面四种情况
- left < mid < right
    - 那么说明数组没有旋转，则 right = mid
- left < mid > right
    - 说明最小值在右侧，left = mid + 1
- left > mid < right
    - 说明最小值在左侧，right = mid
- left > mid > right
    - 由于数组递增，不会出现这种情况

## 代码实现
### 方法1：暴力破解
#### CPP
```C++
class Solution {
public:
    int findMin(vector<int>& nums) {
        int min = 5000;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < min)
                min = nums[i];
        }
        return min;
    }
};
```

### 方法2：二分查找
#### CPP
```C++
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[right])
            {
                right = mid;
            }
            else 
            {
                left = mid + 1;
            }
        }
        return nums[left];
    }
};
```