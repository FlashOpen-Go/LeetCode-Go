# 面试题 01.06. 字符串压缩


## 题目描述
字符串压缩。利用字符重复出现的次数，编写一种方法，实现基本的字符串压缩功能。比如，字符串aabcccccaaa会变为a2b1c5a3。若“压缩”后的字符串没有变短，则返回原先的字符串。你可以假设字符串中只包含大小写英文字母（a至z）。

#### 示例1:
> 输入："aabcccccaaa"
> 输出："a2b1c5a3"

#### 示例2:
> 输入："abbccd"
> 输出："abbccd"
> 解释："abbccd"压缩后为"a1b2c2d1"，比原字符串长度更长。

#### 提示：
> 字符串长度在[0, 50000]范围内。

## 解析
### 方法1：模拟压缩过程
- 遍历字符串记录每一个字符出现的次数


## 代码实现
### 方法1：模拟压缩过程
#### CPP
```C++
class Solution {
public:
    string compressString(string S) {
        string ret = "";
        if (S.length() == 0)
            return ret;
        int count = 0;
        char ch = S[0];
        for (char c : S)
        {
            if (ch == c)
            {
                count++;
            }
            else
            {
                ret += ch + to_string(count);
                ch = c;
                count = 1;
            }
        }
        ret += ch + to_string(count);
        return S.length() > ret.length() ? ret : S;
    }
};
```