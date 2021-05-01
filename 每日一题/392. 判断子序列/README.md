# 392. 判断子序列

## 题目描述
给你一个字符串 s，找到 s 中最长的回文子串。

 

给定字符串 s 和 t ，判断 s 是否为 t 的子序列。

字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。

进阶：

如果有大量输入的 S，称作 S1, S2, ... , Sk 其中 k >= 10亿，你需要依次检查它们是否为 T 的子序列。在这种情况下，你会怎样改变代码？

### 示例 1：
```
输入：s = "abc", t = "ahbgdc"
输出：true
```
### 示例 2：
```
输入：s = "axc", t = "ahbgdc"
输出：false
```

### 提示：

 - 0 <= s.length <= 100
 - 0 <= t.length <= 10^4
 - 两个字符串都只由小写字符组成。

## 解析
- 遍历字串，以子串的每一个字符冲t里面找，每找到一个，以这个位置为下标重新找，直到全找到为止，返回true，否则返回false。



## 代码实现
```Java
class Solution {
    public boolean isSubsequence(String s, String t) {
        int index = -1;
		//遍历s子串，每次找到一个以这个位置为下标至t结束，知道全部找到为止，返回true，否则返回false
		for(char c:s.toCharArray()) {
			index = t.indexOf(c, index+1);
			if(index==-1) {
				return false;
			}
		}
		return true;
    };
```