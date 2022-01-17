# 599. 两个列表的最小索引总和

## 题目描述
假设Andy和Doris想在晚餐时选择一家餐厅，并且他们都有一个表示最喜爱餐厅的列表，每个餐厅的名字用字符串表示。
你需要帮助他们用最少的索引和找出他们共同喜爱的餐厅。 如果答案不止一个，则输出所有答案并且不考虑顺序。 你可以假设总是存在一个答案。

#### 示例 1:
    输入:
    ["Shogun", "Tapioca Express", "Burger King", "KFC"]
    ["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
    输出: ["Shogun"]
    解释: 他们唯一共同喜爱的餐厅是“Shogun”。

#### 示例 2:
    输入:
    ["Shogun", "Tapioca Express", "Burger King", "KFC"]
    ["KFC", "Shogun", "Burger King"]
    输出: ["Shogun"]
    解释: 他们共同喜爱且具有最小索引和的餐厅是“Shogun”，它有最小的索引和1(0+1)。


#### 提示:
    两个列表的长度范围都在 [1, 1000]内。
    两个列表中的字符串的长度将在[1，30]的范围内。
    下标从0开始，到列表的长度减1。
    两个列表都没有重复的元素。


## 解析
#### 方法1：哈希表
1、首先遍历list1，建立哈希表
2、遍历list2，判断元素是否出现在哈希表中
3、如果出现则计算下表差值，若符合条件则记录


## 代码实现
```C++
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> str12list;
        for (int  i = 0; i < list1.size(); i++)
        {
            str12list[list1[i]] = i;
        }
        unordered_map<int, vector<string>> str22list;
        int min = INT_MAX;
        for (int i = 0; i < list2.size(); i++)
        {
            if (str12list.find(list2[i]) != str12list.end())
            {
                int temp = i + str12list[list2[i]];
                if (min >= temp)
                {
                    min = temp;
                    str22list[min].push_back(list2[i]);
                }
            }
        }
        return str22list[min];
    }
};
```