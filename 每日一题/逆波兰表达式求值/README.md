# 逆波兰表达式求值

## 题目描述
根据 逆波兰表示法，求表达式的值。

有效的算符包括 +、-、*、/ 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。

 
##### 说明：
- 整数除法只保留整数部分。
- 给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
 
#### 示例 1：
```c
输入：tokens = ["2","1","+","3","*"]
输出：9
解释：该算式转化为常见的中缀算术表达式为：((2 + 1) * 3) = 9
```

#### 示例 2：
```c
输入：tokens = ["4","13","5","/","+"]
输出：6
解释：该算式转化为常见的中缀算术表达式为：(4 + (13 / 5)) = 6
```

#### 示例 3：
```c
输入：tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
输出：22
解释：
该算式转化为常见的中缀算术表达式为：
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
```
 

##### 提示：
```c
1 <= tokens.length <= 104
tokens[i] 要么是一个算符（"+"、"-"、"*" 或 "/"），要么是一个在范围 [-200, 200] 内的整数
```


## 解析
#### 方法1：栈
- 使用栈来存储数字
- 遍历整个数组，当数据不是操作符时则将其转换为int类型的数据并压栈
- 当遇到操作符时则将栈中的前两个元素弹出，并根据遇到的操作符进行操作
- 计算完成之后再将计算好的数据压栈
- 遍历完成整个字符串数组之后，栈顶元素就是改表达式的结果


## 实现
#### 方法1：栈
##### CPP
```C++
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int ret = 0;
        stack<int> stk;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] == "-")
            {
                int temp1 = stk.top();
                stk.pop();
                int temp2 = stk.top();
                stk.pop();
                stk.push(temp2 - temp1);
            }
            else if (tokens[i] == "+")
            {
                int temp1 = stk.top();
                stk.pop();
                int temp2 = stk.top();
                stk.pop();
                    stk.push(temp2 + temp1);
            }
            else if (tokens[i] == "*")
            {
                int temp1 = stk.top();
                stk.pop();
                int temp2 = stk.top();
                stk.pop();
                    stk.push(temp2 * temp1);
            }
            else if (tokens[i] == "/")
            {
                int temp1 = stk.top();
                stk.pop();
                int temp2 = stk.top();
                stk.pop();
                stk.push(temp2 / temp1);
            }
            else
            {
                stk.push(std::stoi(tokens[i]));
            }

        }
        return stk.top();
    }
};
```