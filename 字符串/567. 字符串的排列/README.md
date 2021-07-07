# 567. 字符串的排列
给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。

换句话说，第一个字符串的排列之一是第二个字符串的 子串 。

 

### 示例 1：
```
输入: s1 = "ab" s2 = "eidbaooo"
输出: True
解释: s2 包含 s1 的排列之一 ("ba").
```
### 示例 2：
```
输入: s1= "ab" s2 = "eidboaoo"
输出: False
```
 

### 提示：

1. 输入的字符串只包含小写字母
2. 两个字符串的长度都在 [1, 10,000] 之间




## 代码实现
```Java
class Solution {
    public boolean checkInclusion(String s1, String s2) {
        int a = s1.length(),b=s2.length();
		if(a>b) return false;
		int[] arr1 = new int[26];
		int[] arr2 = new int[26];
		//遍历前a位，判断是否相等，相等返回true
		for(int i=0;i<a;i++) {
			++arr1[s1.charAt(i)-'a'];
			++arr2[s2.charAt(i)-'a'];
		}
		if(Arrays.equals(arr1, arr2)) {
			return true;
		}
		//滑窗，右边右滑一位，左边右滑一位，保证长度为a，然后判断数组是否相等相等返回true，否则返回false
		for(int j=a;j<b;j++) {
			++arr2[s2.charAt(j)-'a'];
			--arr2[s2.charAt(j-a)-'a'];
			if(Arrays.equals(arr1, arr2)) {
				return true;
			}
		}
		return false;
    }
};
```