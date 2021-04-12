# 剑指 Offer 27. 二叉树的镜像

## 题目描述
请完成一个函数，输入一个二叉树，该函数输出它的镜像。
```
例如输入：

     4
   /   \
  2     7
 / \   / \
1   3 6   9
镜像输出：

     4
   /   \
  7     2
 / \   / \
9   6 3   1

```
### 示例 1：
```
输入：root = [4,2,7,1,3,6,9]
输出：[4,7,2,9,6,3,1]
```

### 限制：
0 <= 节点个数 <= 1000


## 解析
#### 方法1：
- 递归方法，先把左右节点做一个转换，然后把左右节点当入参递归转换
- 这个方法可能会超时，不同递归就用堆或者栈，堆或者栈的方法不会超时
## 代码实现
#### Java
```Java
class Solution {
    public TreeNode mirrorTree(TreeNode root) {
        if(root==null){
            return root;
        }
        TreeNode temp = root.left;
            root.left = root.right;
            root.right = temp;
            mirrorTree(root.left);
            mirrorTree(root.right);
            return root;

    }
};
```

#### Python
```python
class Solution:
    def mirrorTree(self, root: TreeNode) -> TreeNode:
        if not root:
            return root
        # a, b = b, a
        root.left, root.right = self.mirrorTree(root.right), self.mirrorTree(root.left)
        return root
```