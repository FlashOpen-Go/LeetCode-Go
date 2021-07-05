# 88. 合并两个有序数组

## 题目描述
给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。

初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。你可以假设 nums1 的空间大小等于 m + n，这样它就有足够的空间保存来自 nums2 的元素。

 

### 示例 1：
```
输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
输出：[1,2,2,3,5,6]
```
### 示例 2：
```
输入：nums1 = [1], m = 1, nums2 = [], n = 0
输出：[1]
```
 

### 提示：

 - nums1.length == m + n
 - nums2.length == n
 - 0 <= m, n <= 200
 - 1 <= m + n <= 200
 - -109 <= nums1[i], nums2[i] <= 109

## 实现
#### Java
```Java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        //合并后的长度
		int p = m-- + n-- - 1;
		//连个数组倒序进行比较，哪个大赋值给数组1
		while(m>=0&&n>=0) {
			nums1[p--]  = nums1[m]>nums2[n]?nums1[m--]:nums2[n--];
		}
		//如果数组一走完了，那就把数组2剩下的拷贝到数组1剩下的地方，如果数组2走完了，那么不用管的，因为本来修改的及时数组1
		while (n >= 0) {
            nums1[p--] = nums2[n--];
        }
    }
};
```