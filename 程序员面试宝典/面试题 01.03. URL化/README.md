# 面试题 01.03. URL化


## 题目描述
URL化。编写一种方法，将字符串中的空格全部替换为%20。假定该字符串尾部有足够的空间存放新增字符，并且知道字符串的“真实”长度。（注：用Java实现的话，请使用字符数组实现，以便直接在数组上操作。）

#### 示例 1：
> 输入："Mr John Smith    ", 13
> 输出："Mr%20John%20Smith"

#### 示例 2：
> 输入："               ", 5
> 输出："%20%20%20%20%20"
 

#### 提示：
> 字符串长度在 [0, 500000] 范围内。


## 解析
### 方法1：
- 新建字符串，逐个复制，遇到空格则添加标记

## 代码实现
### 方法1：
#### CPP
```C++
class Solution {
public:
    string replaceSpaces(string S, int length) {
        string ret = "";
        ret.resize(S.length());
        int place = 0;
        for (int i = 0; i < length; i++)
        {
            if (S[i] == ' ')
            {
                ret[place++] = '%';
                ret[place++] = '2';
                ret[place++] = '0';
            }
            else
            {
                ret[place++] = S[i];
            }
        }
        return ret;
    }
};
```