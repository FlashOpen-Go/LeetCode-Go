# 557. 反转字符串中的单词 III

## 题目描述
给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

 

### 示例：
```
输入："Let's take LeetCode contest"
输出："s'teL ekat edoCteeL tsetnoc"
```

### 提示：

 - 在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。



## 实现
#### Java
```Java
class Solution {
    public String reverseWords(String s) {
        String nStr = new StringBuffer(s).reverse().toString();
		String[] strArr = nStr.split(" ");
		int left=0,right=strArr.length-1;
		while(left<=right) {
			String temp = strArr[left];
			strArr[left++] = strArr[right];
			strArr[right--] = temp;
		}
		StringBuffer sb = new StringBuffer();
		for(String str:strArr) {
			sb.append(str+" ");
		}
		return sb.toString().trim();
    }
};
```