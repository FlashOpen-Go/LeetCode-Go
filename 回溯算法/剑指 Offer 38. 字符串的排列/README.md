# 剑指 Offer 38. 字符串的排列


## 题目描述
输入一个字符串，打印出该字符串中字符的所有排列。

你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。
 

#### 示例:
> 输入：s = "abc"
> 输出：["abc","acb","bac","bca","cab","cba"]
 

#### 限制：
> 1 <= s 的长度 <= 8


## 解析


## 代码实现
### 方法1：回溯
#### CPP
```C++
class Solution {
public:
    vector<string> permutation(string s) {
        vector<string> ret;
        vector<bool> flagArray(s.size(), false);
        sort(s.begin(), s.end());
        int index = 0;
        string str = "";
        backtrack(s, ret, str, index, flagArray);
        return ret;
    }
    void backtrack(string s, vector<string>& ret_str, string& str, int index, vector<bool>& flagArray)
    {
        if (str.length() == s.length())
        {
            ret_str.push_back(str);
            return;
        }
        for (int i = 0; i < s.length(); i++)
        {
            if (flagArray[i] || (i > 0 && !flagArray[i - 1] && s[i] == s[i - 1]) )
                continue;
            flagArray[i] = true;
            str.push_back(s[i]);
            backtrack(s, ret_str, str, index + 1, flagArray);
            str.pop_back();
            flagArray[i] = false;
        }
    }
};
```