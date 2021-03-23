# 扁平化嵌套列表迭代器

## 题目描述
给你一个嵌套的整型列表。请你设计一个迭代器，使其能够遍历这个整型列表中的所有整数。
列表中的每一项或者为一个整数，或者是另一个列表。其中列表的元素也可能是整数或是其他列表。

#### 示例 1:
```c
输入: [[1,1],2,[1,1]]
输出: [1,1,2,1,1]
解释: 通过重复调用 next 直到 hasNext 返回 false，next 返回的元素的顺序应该是: [1,1,2,1,1]。
```

#### 示例 2:
```c
输入: [1,[4,[6]]]
输出: [1,4,6]
解释: 通过重复调用 next 直到 hasNext 返回 false，next 返回的元素的顺序应该是: [1,4,6]。
```

## 解析
#### 方法1:
- 解析题目：存在一个NestedInteger类，里面可以存储单个数字，也可以存储一个类似于数组的数据。isInteger方法用来判断是否是单个数据，getInteger方法用来获取单个数据，getList方法来获取数组
- 该结构类似于树结构，叶子节点就是单个数据，子树结构就是数组
- 可以使用递归来进行遍历，如果当前对象是一个单个数据则添加到数组总，否则获取数据再进行处理，直到结束。

## 代码实现
#### 方法1：
##### CPP
```C++
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    vector<int> m_array;
    vector<int>::iterator cur;

    void addItems(vector<NestedInteger>& nestedList)
    {
        for (auto a : nestedList)
        {
            if (a.isInteger())
            {
                m_array.push_back(a.getInteger());
            }
            else
            {
                addItems(a.getList());
            }
        }
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        addItems(nestedList);
        cur = m_array.begin();
    }
    
    int next() {
        return *cur++;
    }
    
    bool hasNext() {
        return cur != m_array.end();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
```