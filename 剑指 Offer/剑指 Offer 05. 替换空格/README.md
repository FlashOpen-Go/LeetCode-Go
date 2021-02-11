# 剑指 Offer 05. 替换空格

## 题目描述
请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

```c
示例 1：
输入：s = "We are happy."
输出："We%20are%20happy."

限制：
0 <= s 的长度 <= 10000
```

## 解析

## 代码实现
#### 方法1
- 使用C++的特性，直接遍历字符串，逐个添加，遇到空格时，则添加 "%20"

#### 方法2
- 首先遍历字符串，确定空格数
- 创建大小匹配的字符串
- 逐个遍历添加到字符串中

#### CPP
```C++
class Solution {
public:
    string replaceSpace(string s) {
        string ret = "";
        for (int i = 0 ; i < s.length(); i++)
        {
            if (s[i] == ' ')
            {
                ret.push_back('%');
                ret.push_back('2');
                ret.push_back('0');
            }
            else
            {
                ret.push_back(s[i]);
            }
            
        }
        return ret; 
    }
};
```

```C++
class Solution {
public:
    string replaceSpace(string s) {
        int length = s.length();
        int space_count = 0;
        string ret = "";
        for (int i = 0; i < length; i++)
        {
            if (s[i] == ' ')
                space_count++;
        }
        ret.resize(length + space_count * 2);
        int j = 0;
        for (int i = 0; i < length; i++)
        {
            if (s[i] == ' ')
            {
                cout << s[i] << endl;
                ret[j++] = '%';
                ret[j++] = '2';
                ret[j] = '0';
            }
            else
            {
                ret[j] = s[i];
            }
            j++;
        }
        return ret;
    }
};
```