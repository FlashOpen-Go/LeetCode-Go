# 942. 增减字符串匹配

## 题目描述
由范围 [0,n] 内所有整数组成的 n + 1 个整数的排列序列可以表示为长度为 n 的字符串 s ，其中:

 - 如果 perm[i] < perm[i + 1] ，那么 s[i] == 'I' 
 - 如果 perm[i] > perm[i + 1] ，那么 s[i] == 'D' 
给定一个字符串 s ，重构排列 perm 并返回它。如果有多个有效排列perm，则返回其中 任何一个 。

 

### 示例 1：
```
输入：s = "IDID"
输出：[0,4,1,3,2]
```
### 示例 2：
```
输入：s = "III"
输出：[0,1,2,3]
```
### 示例 3：
```
输入：s = "DDI"
输出：[3,2,0,1]
```
 

### 提示：

 - 1 <= s.length <= 105
 - s 只包含字符 "I" 或 "D"



## 解析
- 维护左右两个指针
- 遍历传入的字符串，如果是I，就从剩下的选择最小的，如果是D,就从剩下的选择最大的
- 贪心算法加上双指针



## 代码实现
```Java
class Solution {
    public int[] diStringMatch(String s) {
        int i=0,left=0,right=s.length();
        int[] nums = new int[s.length()+1];
        while(i<s.length()){
            if(s.charAt(i)=='I'){
                nums[i] = left++;
                i++;
            }else{
                nums[i] = right--;
                i++;
            }
        }
        nums[s.length()] = right;
        return nums;
    }
};
```