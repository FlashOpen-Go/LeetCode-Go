# 键盘行

## 题目描述
给你一个字符串数组 words ，只返回可以使用在 美式键盘 同一行的字母打印出来的单词。键盘如下图所示。
美式键盘 中：
- 第一行由字符 "qwertyuiop" 组成。
- 第二行由字符 "asdfghjkl" 组成。
- 第三行由字符 "zxcvbnm" 组成。
![Image text](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/keyboard.png)

#### 示例 1:
```
输入：words = ["Hello","Alaska","Dad","Peace"]
输出：["Alaska","Dad"]
```
#### 示例 2:
```
输入：words = ["omk"]
输出：[]
```
#### 示例 3:
```
输入：words = ["adsdf","sfd"]
输出：["adsdf","sfd"]
```
提示：

- 1 <= words.length <= 20
- 1 <= words[i].length <= 100
- words[i] 由英文字母（小写和大写字母）组成

## 解析
#### CPP实现
- 创建数组记录每个字符出现的行号，之后依次遍历每个字符串，判断行号是否唯一

## 代码实现
#### Python3
```python
class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        set1 = set('qwertyuiop')
        set2 = set('asdfghjkl')
        set3 = set('zxcvbnm')
        res = []
        for i in words:
            x = i.lower()
            setx = set(x)
            if setx <= set1 or setx <= set2 or setx <= set3:
                res.append(i)
        return res
```

#### CPP
```C++
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<int> array ={2, 3, 3, 2, 1, 2, 2, 2, 1, 2, 2, 2, 3, 3, 1, 1, 1, 1, 2, 1, 1, 3, 1, 3, 1, 3};
        vector<string> ret;
        for (string s : words)
        {
            int temp = 0;
            bool flag = true;
            string temp_str = s;
            transform(temp_str.begin(), temp_str.end(), temp_str.begin(), ::toupper);
            temp = array[(temp_str[0] - 'A')];
            for (char c : temp_str)
            {
                if (array[(c - 'A')] != temp)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                ret.push_back(s);
        }
        return ret;
    }
};
```