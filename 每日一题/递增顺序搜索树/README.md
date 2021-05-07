# 897. 递增顺序搜索树

## 题目描述
给你一棵二叉搜索树，请你 按中序遍历 将其重新排列为一棵递增顺序搜索树，使树中最左边的节点成为树的根节点，并且每个节点没有左子节点，只有一个右子节点。

 

### 示例 1：
<img src="https://assets.leetcode.com/uploads/2020/11/17/ex1.jpg">
```
输入：root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
输出：[1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
```
### 示例 2：

```
输入：root = [5,1,7]
输出：[1,null,5,null,7]
```
 

### 提示：

 - 树中节点数的取值范围是 [1, 100]
 - 0 <= Node.val <= 1000


## 解析
- 新建一个树
- 中序遍历，把当前值放入新建的树的右子树
- 返回新建的树



## 代码实现
```Java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private TreeNode dummyNode = new TreeNode();
    private TreeNode resRight = dummyNode;
    public TreeNode increasingBST(TreeNode root) {
        dfs(root);
        return dummyNode.right;
    }
    private void dfs (TreeNode root) {
        if (null == root) {
            return;
        }
        dfs(root.left);
        resRight.right = new TreeNode(root.val);
        resRight = resRight.right;
        dfs(root.right);
    }
};
```