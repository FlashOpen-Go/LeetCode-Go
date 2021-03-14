# 设计哈希集合
不使用任何内建的哈希表库设计一个哈希集合（HashSet）。

实现 MyHashSet 类：

void add(key) 向哈希集合中插入值 key 。
bool contains(key) 返回哈希集合中是否存在这个值 key 。
void remove(key) 将给定值 key 从哈希集合中删除。如果哈希集合中没有这个值，什么也不做。
 
#### 示例：
```c
输入：
["MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"]
[[], [1], [2], [1], [3], [2], [2], [2], [2]]
输出：
[null, null, null, true, false, null, true, null, false]

解释：
MyHashSet myHashSet = new MyHashSet();
myHashSet.add(1);      // set = [1]
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(1); // 返回 True
myHashSet.contains(3); // 返回 False ，（未找到）
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(2); // 返回 True
myHashSet.remove(2);   // set = [1]
myHashSet.contains(2); // 返回 False ，（已移除）
``` 

```c
提示：
0 <= key <= 106
最多调用 104 次 add、remove 和 contains 。
```

## 题目描述


## 解析
### 方法1：暴力破解
- 由于skey范围是有限的，因此可以直接创建一个指定大小的数组
- 之后的所有操作都是基于这个数组的索引来进行即可


## 代码实现
### 方法1：暴力破解
#### CPP
```C++
class MyHashSet {
vector<int> ret;
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        ret.resize(1000005);
    }
    
    void add(int key) {
        ret[key] = 1;
    }
    
    void remove(int key) {
        ret[key] = 0;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return ret[key] == 1;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
```