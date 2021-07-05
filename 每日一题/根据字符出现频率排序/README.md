# 根据字符出现频率排序

## 题目描述
给定一个字符串，请将字符串里的字符按照出现的频率降序排列。

#### 示例 1:
> 输入:
> "tree"
> 
> 输出:
> "eert"

> 解释:
>
> 'e'出现两次，'r'和't'都只出现一次。
>
> 因此'e'必须出现在'r'和't'之前。此外，"eetr"也是一个有效的答案。

#### 示例 2:
> 
> 输入:
> "cccaaa"
> 
> 输出:
> "cccaaa"

> 解释:
>
> 'c'和'a'都出现三次。此外，"aaaccc"也是有效的答案。
>
> 注意"cacaca"是不正确的，因为相同的字母必须放在一起。

#### 示例 3:
> 输入:
> "Aabb"
> 
> 输出:
> "bbAa"

> 解释:
>
> 此外，"bbaA"也是一个有效的答案，但"Aabb"是不正确的。
>
> 注意'A'和'a'被认为是两种不同的字符。

## 解析
### 方法1：使用hash表实现
- 使用 unordered_map<char, int> m_map 来记录每一个元素出现的次数，构建一个键值对
- 之后使用sort方法，配合 m_map 来进行排序

## 代码实现
### 方法1：使用hash表实现
#### CPP
```C++
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m_map;
        for (auto c : s )
        {
            m_map[c]++;
        }
        sort(s.begin(), s.end(), [&](const char& a, const char& b){return (m_map[a] == m_map[b] ? a > b : m_map[a] > m_map[b]);});
        return s;
    }
};
```