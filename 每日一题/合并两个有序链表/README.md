# 21. 合并两个有序链表

## 题目描述
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

 
### 示例 1：
<img src="https://assets.leetcode.com/uploads/2020/10/03/merge_ex1.jpg"/>
```
输入：l1 = [1,2,4], l2 = [1,3,4]
输出：[1,1,2,3,4,4]
```
### 示例 2：
```
输入：l1 = [], l2 = []
输出：[]
```
### 示例 3：
```
输入：l1 = [], l2 = [0]
输出：[0]
```

### 提示：

 - 两个链表的节点数目范围是 [0, 50]
 - -100 <= Node.val <= 100
 - l1 和 l2 均按 非递减顺序 排列



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