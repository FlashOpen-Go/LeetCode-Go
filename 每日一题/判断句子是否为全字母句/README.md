# 判断句子是否为全字母句

## 题目描述
全字母句 指包含英语字母表中每个字母至少一次的句子。
给你一个仅由小写英文字母组成的字符串 sentence ，请你判断 sentence 是否为 全字母句 。
如果是，返回 true ；否则，返回 false 。


#### 示例 1：
> 输入：sentence = "thequickbrownfoxjumpsoverthelazydog"
> 输出：true
> 解释：sentence 包含英语字母表中每个字母至少一次。

#### 示例 2：
> 输入：sentence = "leetcode"
> 输出：false
 
#### 提示：
> 1 <= sentence.length <= 1000
> sentence 由小写英语字母组成


## 解析
### 方法1：位运算
- 使用一个int类型变量的26位来记录每一个字母，初始化26位位全1
- 遍历字符串，将对应字符串的那个bit置0
- 最后判断变量是否为0即可

## 代码实现
### CPP
#### 方法1：位运算
```CPP
class Solution {
public:
    bool checkIfPangram(string sentence) {
        int value = 0x3FFFFFF;
        for (char c : sentence)
        {
            value &= ~(1 << (c - 'a'));
        }
        return (value == 0);
    }
};
```