# 22. 括号生成

## 题目描述
数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

 
### 示例 1：
```
输入：n = 3
输出：["((()))","(()())","(())()","()(())","()()()"]
```
### 示例 2：
```
输入：n = 1
输出：["()"]
```

### 提示：

 - 1 <= n <= 8

### 解析
- 用left和right维护剩余的左括号和右括号
- 如果又左括号，拼上左括号
- 如果左括号多于右括号，拼上右括号



## 代码实现
```Java
class Solution {
    List<String> res = new LinkedList<String>();
    public List<String> generateParenthesis(int n) {
        List<String> res = new LinkedList<String>();
		generate(res,"",n,n);
		return res;
    }
    public void generate(List<String> res,String str,int left, int right) {
		if(left==0&&right==0) {
			res.add(str);
			return;
		}
		//如果还有左括号，拼上一个左括号
		if(left>0) {
			generate(res, str+"(",left-1,right);
		}
		//左括号多余右括号，拼上一个右括号
		if(left<right) {
			generate(res, str+")",left,right-1);
		}
	}
};
```