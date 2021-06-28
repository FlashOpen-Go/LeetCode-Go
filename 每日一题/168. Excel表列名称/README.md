# 168. Excel表列名称

## 题目描述
给定一个正整数，返回它在 Excel 表中相对应的列名称。

例如，
```
    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
    ...
```
### 示例 1:
```
输入: 1
输出: "A"
```
### 示例 2:
```
输入: 28
输出: "AB"
```
### 示例 3:
```
输入: 701
输出: "ZY"
```

### 解析
 - 首先对26取余获取尾部串，然后取整继续循环，重新取余继续追加，直到等于0为止
 - 因为是用尾插法的，所以需要对结果倒序返回



## 代码实现
```Java
class Solution {
    public String convertToTitle(int columnNumber) {
        StringBuffer sb = new StringBuffer();
		while((columnNumber-1)/26>=0&&columnNumber!=0) {
			int t = columnNumber%26;
			t = t==0?26:t;
			//获取与下来的字符
			char a = (char)(t+64);
			sb.append(a+"");
			columnNumber=(columnNumber-1)/26;
			//System.out.println(columnNumber);
		}
		//一位内是尾部追加的，所以需要倒序
		return sb.reverse().toString();
    }
};
```