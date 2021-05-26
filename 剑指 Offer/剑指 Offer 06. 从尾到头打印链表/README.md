# 剑指 Offer 06. 从尾到头打印链表

## 题目描述
剑指 Offer 06. 从尾到头打印链表
输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

 

### 示例 1：
```
输入：head = [1,3,2]
输出：[2,3,1]
```

限制：

0 <= 链表长度 <= 10000




## 代码实现
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
    public int[] reversePrint(ListNode head) {
        if(head==null) {
			return new int[0];
		}
		List<Integer> list = new ArrayList<Integer>();
		while(head!=null) {
			list.add(0, head.val);
			head = head.next;
		}
		return list.stream().mapToInt(Integer::valueOf).toArray();
    }
};
```
#### Python3
```python
class Solution:
    def reversePrint(self, head: ListNode) -> List[int]:
        a = []
        while head:
            a.append(head.val)
            head = head.next
        return a[::-1]
```