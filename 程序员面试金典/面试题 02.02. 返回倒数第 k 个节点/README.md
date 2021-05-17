# 面试题 02.02. 返回倒数第 k 个节点

## 题目描述
实现一种算法，找出单向链表中倒数第 k 个节点。返回该节点的值。

注意：本题相对原题稍作改动

### 示例：
```
输入： 1->2->3->4->5 和 k = 2
输出： 4
说明：
```

给定的 k 保证是有效的。





## 代码实现
### 方法1：
#### Java
```Java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public int kthToLast(ListNode head, int k) {
        List<Integer> list = new ArrayList<Integer>();
		while(head!=null) {
			list.add(head.val);
			head = head.next;
		}
		return list.get(list.size()-k);
    }
};
```