# 剑指 Offer 35. 复杂链表的复制

## 题目描述
请实现 copyRandomList 函数，复制一个复杂链表。在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，还有一个 random 指针指向链表中的任意节点或者 null。

 

###  示例 1：
![图解](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/01/09/e1.png)
```
输入：head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
输出：[[7,null],[13,0],[11,4],[10,2],[1,0]]
```

### 示例 2：
![图解](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/01/09/e2.png)
```
输入：head = [[1,1],[2,1]]
输出：[[1,1],[2,1]]
```
### 示例 3：
![](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/01/09/e3.png)
```
输入：head = [[3,null],[3,0],[3,null]]
输出：[[3,null],[3,0],[3,null]]
```
### 示例 4：
```
输入：head = []
输出：[]
解释：给定的链表为空（空指针），因此返回 null。
```


### 提示：

 - -10000 <= Node.val <= 10000
 - Node.random 为空（null）或指向链表中的节点。
 - 节点数目不超过 1000 。

## 解析
 - 先用hash表存储所有节点，然后遍历hash表设置next节点和random节点

## 代码实现
#### Java
```Java
/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/
class Solution {
    public Node copyRandomList(Node head) {
		if(head == null) return null;
		Node curr = head;
		Map<Node, Node> map = new HashMap<>();
		while(curr != null) {
			map.put(curr, new Node(curr.val));
			curr = curr.next;
		}
		curr = head;
		while(curr != null) {
			map.get(curr).next = map.get(curr.next);
			map.get(curr).random = map.get(curr.random);
			curr = curr.next;
		}
        return map.get(head);
    }
};
```