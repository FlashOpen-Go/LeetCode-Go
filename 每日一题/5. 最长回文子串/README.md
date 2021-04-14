# 5. 最长回文子串

## 题目描述
给你一个字符串 s，找到 s 中最长的回文子串。

 

### 示例 1：
```
输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。
```
### 示例 2：
```
输入：s = "cbbd"
输出："bb"
```
### 示例 3：
```
输入：s = "a"
输出："a"
```
### 示例 4：
```
输入：s = "ac"
输出："a"
```
###提示：

 - 1 <= s.length <= 1000
 - s 仅由数字和英文字母（大写和/或小写）组成

## 解析
- 维护一个串，存最大值
- 从入参的每一位开始遍历，
- 以i位为中心和以i与i+1为中心传入函数取最长字符串



## 代码实现
```Java
class Solution {
    public String longestPalindrome(String s) {
        String ret = "";
		for(int i=0;i<s.toCharArray().length;i++) {
            //要么时以i为中心回文，要么是一i和i+1为中心回文，取最长值
			String myStr = getLenStr(s,i,i);
			String broStr = getLenStr(s, i, i+1);
			String str = myStr.length()>broStr.length()?myStr:broStr;
			ret = str.length()>ret.length()?str:ret;
		}
		return ret;
    }
    public String getLenStr(String s,int left,int right) {
		while(left>0&&right<s.length()&&s.charAt(left-1)==s.charAt(right)) {
			left--;
			right++;
		}
        //当s.charAt(left-1)！=s.charAt(right)就不是回文所以返回
		return s.substring(left,right);
	}
};
```