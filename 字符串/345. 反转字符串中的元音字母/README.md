# 345. 反转字符串中的元音字母
给你一个字符串 s ，仅反转字符串中的所有元音字母，并返回结果字符串。

元音字母包括 'a'、'e'、'i'、'o'、'u'，且可能以大小写两种形式出现。

 

### 示例 1：
```
输入：s = "hello"
输出："holle"
```
### 示例 2：
```
输入：s = "leetcode"
输出："leotcede"
```
 

### 提示：

 - 1 <= s.length <= 3 * 105
 - s 由 可打印的 ASCII 字符组成



## 代码实现
```Java
class Solution {
    public String reverseVowels(String s) {
        char[] chars = s.toCharArray();
		StringBuffer sb = new StringBuffer();
		int left=0,right = chars.length-1;
		String str = "aeiouAEIOU";
		while(left<=right) {
			char l = chars[left];
			char r = chars[right];
			if(str.indexOf(l)>=0&&str.indexOf(r)>=0) {
				char temp = chars[left];
				chars[left++] = chars[right];
				chars[right--] = temp;
			}else {
				if(str.indexOf(l)==-1) {
					left++;
				}
				if(str.indexOf(r)==-1) {
					right--;
				}
			}
		}
		
		for(int i=0;i<chars.length;i++) {
			sb.append(chars[i]);
		}
		return sb.toString();
    }
};
```