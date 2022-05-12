# 剑指 Offer 28. 对称的二叉树

## 题目描述
请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
```
    1
   / \
  2   2
 / \ / \
3  4 4  3
```
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
```
    1
   / \
  2   2
   \   \
   3    3
```

 

### 示例 1：
```
输入：root = [1,2,2,3,4,4,3]
输出：true
```
### 示例 2：
```
输入：root = [1,2,2,null,3,null,3]
输出：false
```
 

### 限制：

 - 0 <= 节点个数 <= 1000

注意：本题与主站 101 题相同：https://leetcode-cn.com/problems/symmetric-tree/



## 解析
#### 方法1：
- 迭代方法，利用队列一次假如左左右右，以及左右右左子树，然后一次弹出两个子树
- 如果都是空则跳过，如果一个为空或者值不一样，则返回false，
- 以上不发生则返回true
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
    public boolean isSymmetric(TreeNode root) {
        return check(root, root);
    }

    public boolean check(TreeNode root1, TreeNode root2) {
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root1);
        queue.add(root2);
        while (!queue.isEmpty()){
            TreeNode poll = queue.poll();
            TreeNode poll1 = queue.poll();
            if(poll==null&&poll1==null){
                continue;
            }
            if((poll==null||poll1==null)||(poll.val!=poll1.val)){
                return false;
            }
            
            queue.add(poll.left);
            queue.add(poll1.right);
            
            queue.add(poll.right);
            queue.add(poll1.left);
        }
        return true;
    }
};
```