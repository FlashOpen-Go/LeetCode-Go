# 剑指 Offer 55 - I. 二叉树的深度

## 题目描述
输入一棵二叉树的根节点，求该树的深度。从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，最长路径的长度为树的深度。

例如：
给定二叉树 [3,9,20,null,null,15,7]，
```
    3
   / \
  9  20
    /  \
   15   7
```
返回它的最大深度 3 。

提示：
- 节点总数 <= 10000

## 代码实现
#### Python
```python
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if not root: return 0
        # 树的深度 = max(左子树的深度, 右子树的深度) + 1
        return max(self.maxDepth(root.left), self.maxDepth(root.right)) + 1
```