# 剑指 Offer 40. 最小的k个数

## 题目描述
输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。

```c
示例 1：
输入：arr = [3,2,1], k = 2
输出：[1,2] 或者 [2,1]

示例 2：
输入：arr = [0,1,2,1], k = 1
输出：[0]

限制：
0 <= k <= arr.length <= 10000
0 <= arr[i] <= 10000
```

## 解析
#### 方法1：
- 首先对数组按照从小到大的排序，排序完成后，数组中最小的数据就是前面的 K 个
- 在循环将数据添加到新的数组中即可。

## 代码实现
```C++
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        int count = arr.size();
        vector<int> ret;
        sort(arr.begin(), arr.end());
        for (int i = 0 ; i < k; i++)
            ret.push_back(arr[i]);
        return ret;
    }
};
```