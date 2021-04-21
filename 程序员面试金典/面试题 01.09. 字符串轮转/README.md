# 面试题 01.09. 字符串轮转

## 题目描述
字符串轮转。给定两个字符串s1和s2，请编写代码检查s2是否为s1旋转而成（比如，waterbottle是erbottlewat旋转后的字符串）。

#### 示例1:
> 输入：s1 = "waterbottle", s2 = "erbottlewat"
> 输出：True

#### 示例2:
> 输入：s1 = "aa", s2 = "aba"
> 输出：False

##### 提示：
> 字符串长度在[0, 100000]范围内。

##### 说明:
> 你能只调用一次检查子串的方法吗？

## 解析
### 方法1：
- 首先判断两个字符串的长度是否相等
- 如果S2是S1的旋转，那么S2首尾相连之后，S1一定是S2首位相连后的子串

## 代码实现
### 方法1：
#### CPP
```C++
class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        if (s1.length() != s2.length())
            return false;
        return ((s2 + s2).find(s1) != -1);
    }
};
```