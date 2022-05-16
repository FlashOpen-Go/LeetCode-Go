# 面试题 04.06. 后继者

## 题目描述
设计一个算法，找出二叉搜索树中指定节点的“下一个”节点（也即中序后继）。

如果指定节点没有对应的“下一个”节点，则返回null。
```
### 示例 1:

输入: root = [2,1,3], p = 1

  2
 / \
1   3

输出: 2
```
### 示例 2:
```
输入: root = [5,3,6,2,4,null,null,1], p = 6

      5
     / \
    3   6
   / \
  2   4
 /   
1

输出: null
```



## 代码实现
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
    public TreeNode inorderSuccessor(TreeNode root, TreeNode p) {
        if(root == null){
            return null;
        }
        if(p.val >= root.val){
            return inorderSuccessor(root.right, p);
        }

        TreeNode treeNode = inorderSuccessor(root.left, p);

        return treeNode == null?root:treeNode;
    }
};
```