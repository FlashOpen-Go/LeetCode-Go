# 14. 最长公共前缀

## 题目描述
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

 

### 示例 1：
```
输入：strs = ["flower","flow","flight"]
输出："fl"
```
### 示例 2：
```
输入：strs = ["dog","racecar","car"]
输出：""
解释：输入不存在公共前缀。
```
 

### 提示：

 - 0 <= strs.length <= 200
 - 0 <= strs[i].length <= 200
 - strs[i] 仅由小写英文字母组成



## 代码实现
```Java
class Solution {
    public String longestCommonPrefix(String[] strs) {
        String commStr = strs[0];
		for(int i=1;i<strs.length;i++) {
			int minLen = Math.min(commStr.length(), strs[i].length());
			int idx=0;
			while(idx<minLen) {
				if(commStr.charAt(idx)==strs[i].charAt(idx)) {
					idx++;
				}else {
					break;
				}
			}
			commStr = commStr.substring(0, idx);
		}
		return commStr;
    }
};
```