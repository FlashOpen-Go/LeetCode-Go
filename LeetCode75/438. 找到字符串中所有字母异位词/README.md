# 438. 找到字符串中所有字母异位词

给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。

异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。

 

### 示例 1:
```
输入: s = "cbaebabacd", p = "abc"
输出: [0,6]
解释:
起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
```
###  示例 2:
```
输入: s = "abab", p = "ab"
输出: [0,1,2]
解释:
起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。
```

### 提示:

 - 1 <= s.length, p.length <= 3 * 104
 - s 和 p 仅包含小写字母


## 代码实现
#### Java
```Java
class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> list = new ArrayList<>();
        int left = 0,right = 0;
        int[] arra = new int[1000];
        int[] arrb = new int[1000];
        for(int i=0;i<p.length();i++){
            arrb[p.charAt(i)] = arrb[p.charAt(i)]+1;
        }
        while (right<s.length()){
            if(right-left==p.length()-1){
                arra[s.charAt(right)] = arra[s.charAt(right)]+1;
                if(Arrays.equals(arra, arrb)){
                    list.add(left);
                }
                arra[s.charAt(left)] = arra[s.charAt(left)]-1;
                left++;
                right++;
            }else{
                arra[s.charAt(right)] = arra[s.charAt(right)]+1;
                right++;

            }
        }
        return list;
    }
};
```