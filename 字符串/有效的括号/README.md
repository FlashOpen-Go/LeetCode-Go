# 20. 有效的括号

给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
 

### 示例 1：
```
输入：s = "()"
输出：true
```
### 示例 2：
```
输入：s = "()[]{}"
输出：true
```
### 示例 3：
```
输入：s = "(]"
输出：false
```
### 示例 4：
```
输入：s = "([)]"
输出：false
```
### 示例 5：
```
输入：s = "{[]}"
输出：true
```
 

提示：

 - 1 <= s.length <= 104
 - s 仅由括号 '()[]{}' 组成



## 代码实现
```Java
class Solution {
    /**
	 * 
	 * @param s
	 * @return
	 * 如果是(,[,{就把),],}压入栈中，如果不是就弹出栈首，如果栈为空或者弹出的元素不等于当前字符，则不是一个合格的括号，返回false
	 * 否则返回true
	 */
    public boolean isValid(String s) {
        if(s.length()==0) {
			return true;
		}
		Stack stack = new Stack();
		for(char c:s.toCharArray()) {
			if(c=='(') {
				stack.push(')');
			}
			else if(c=='[') {
				stack.push(']');
			}
			else if(c=='{') {
				stack.push('}');
			}
			else if(stack.empty()||c!=(char)stack.pop()) {
				return false;
			}
		}
		return stack.isEmpty();
    }
};
```