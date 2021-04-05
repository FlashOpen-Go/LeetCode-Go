# 剑指 Offer 32 - I. 从上到下打印二叉树

## 题目描述
从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。

### 示例 1：

例如:
给定二叉树: [3,9,20,null,null,15,7],

```
    3
   / \
  9  20
    /  \
   15   7
```

返回：
```
[3,9,20,15,7]
```

### 限制：
节点总数 <= 1000


## 解析
#### 方法1：
- 二叉树的层序遍历

## 代码实现
#### Java
```Java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public int[] levelOrder(TreeNode root) {
        if(root==null) {return new int[0];}
        //初始化一个队列
		Queue<TreeNode> queue = new LinkedList<TreeNode>();
		List<Integer> list = new ArrayList<Integer>();
        //把这个二叉树放入这个队列
		queue.add(root);
		while(!queue.isEmpty()) {
            //弹出这个队列顶部元素
			TreeNode poll = queue.poll();
			list.add(poll.val);
            //把这个元素的左子节点和右子节点插入
			if(poll.left!=null) queue.add(poll.left);
			if(poll.right!=null) queue.add(poll.right);
		}
		return list.stream().mapToInt(Integer::intValue).toArray();
    }
};
```