# 28. 实现 strStr()

## 题目描述
实现 strStr() 函数。

给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串出现的第一个位置（下标从 0 开始）。如果不存在，则返回  -1 。

 

### 说明：

当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。

对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与 C 语言的 strstr() 以及 Java 的 indexOf() 定义相符。


### 示例 1：
```
输入：haystack = "hello", needle = "ll"
输出：2
```
### 示例 2：
```
输入：haystack = "aaaaa", needle = "bba"
输出：-1
```
### 示例 3：
```
输入：haystack = "", needle = ""
输出：0
```

### 提示：

 - 0 <= haystack.length, needle.length <= 5 * 104
 - haystack 和 needle 仅由小写英文字符组成

### 思路：
- 先找到needle的第一个字符在haystack出现的位置k
- 从k开始计算后续重复的次数，知道连续出现len(needle)次，返回位置k，否则返回-1





## 代码实现
#### Java
```Java
class Solution {
    public int strStr(String haystack, String needle) {
		if(needle.length()==0) {
			return 0;
		}
		char[] hayArray = haystack.toCharArray();
		char[] neeArray = needle.toCharArray();
		int lenHay = hayArray.length;
		int lenNee = needle.length();
		int i = neeArray[0];
		int j=lenHay-lenNee;
		for(int k=0;k<=j;k++) {
			//判断什么时候目的字符串的第一个字符在源字符串出现
			if(hayArray[k]!=i) {
				do
					k++;
				while((k<=j)&&(hayArray[k]!=i));
			}
			if(k<=j) {
				//设置出现的第一个位置此时hayArray[k]==neeArray[0]
				int m=k+1;
				int n = m+lenNee-1;
				//判断从k开始有多少个一样的
				for(int t=1;(m<n)&&(hayArray[m]==neeArray[t]);t++) {
					m++;
				}
				//如果m=n说明从k开始有lenNee个重复字符，说明这是needle在haystack的第一个出现位置，返回k就是地址
				if(m==n) {
					return k;
				}
			}
		}
		return -1;
    }
};
```