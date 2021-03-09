# 删除字符串中的所有相邻重复项

## 题目描述
给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。
在 S 上反复执行重复项删除操作，直到无法继续删除。
在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。

```c
示例：
输入："abbaca"
输出："ca"
解释：
例如，在 "abbaca" 中，我们可以删除 "bb" 由于两字母相邻且相同，这是此时唯一可以执行删除操作的重复项。之后我们得到字符串 "aaca"，其中又只有 "aa" 可以执行重复项删除操作，所以最后的字符串为 "ca"。
 
提示：
1 <= S.length <= 20000
S 仅由小写英文字母组成。
```

## 解析
#### 方法1：栈
- 直接遍历字符串，将每个元素与栈顶元素进行比较
- 如果和栈顶元素相同，则弹出栈顶元素
- 如果不相同则入栈


## 代码实现

#### 方法1
##### CPP
```C++
class Solution {
public:
    string removeDuplicates(string S) {
        if (S.length() < 2)
            return S;
        string ret;
        for (int i = 0; i < S.length(); i++)
        {
            if (!ret.empty() && ret.back() == S[i])
            {
                ret.pop_back();
            }
            else
            {
                ret.push_back(S[i]);
            }
        }
        return ret;
    }
};
```