# 187. 重复的DNA序列

## 题目描述
所有 DNA 都由一系列缩写为 'A'，'C'，'G' 和 'T' 的核苷酸组成，例如："ACGAATTCCG"。在研究 DNA 时，识别 DNA 中的重复序列有时会对研究非常有帮助。

编写一个函数来找出所有目标子串，目标子串的长度为 10，且在 DNA 字符串 s 中出现次数超过一次。

### 示例 1:
```
输入：s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
输出：["AAAAACCCCC","CCCCCAAAAA"]
```
### 示例 2:
```
输入：s = "AAAAAAAAAAAAA"
输出：["AAAAAAAAAA"]
```

### 提示：
 - 0 <= s.length <= 105
 - s[i] 为 'A'、'C'、'G' 或 'T'

## 代码实现
#### Python3
```python
class Solution:
    def findRepeatedDnaSequences(self, s: str) -> list:
        sub_dict = {}
        res = []
        for i in range(len(s)-10+1):
            sub_dna = s[i:i+10]
            if sub_dna in sub_dict.keys():
                sub_dict[sub_dna] += 1
                if sub_dict[sub_dna] == 2:
                    res.append(sub_dna)
            else:
                sub_dict[sub_dna] = 1
        return res
```