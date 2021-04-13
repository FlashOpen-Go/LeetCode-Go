# 二叉搜索树节点最小距离


## 题目描述
给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。
 
#### 示例 1：
![](bst1.jpg)
> 输入：root = [4,2,6,1,3]
> 输出：1

#### 示例 2：
![](bst2.jpg)
> 输入：root = [1,0,48,null,null,12,49]
> 输出：1
 

##### 提示：
> 树中节点数目在范围 [2, 100] 内
> 0 <= Node.val <= 105


## 解析
### 方法1：中序遍历
- 对于一个二叉搜索树，其一定是有序的，右节点 大于 左节点
- 当使用中序遍历时，得到的将会是一个有序的数组
- 之后求相邻的最小值即可

## 代码实现
### 方法1：中序遍历
#### C++
```CPP
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> m_array;
    void fun(TreeNode* root)
    {
        if (root == nullptr )   return;
        fun(root->left);
        m_array.push_back(root->val);
        fun(root->right);
    }

    int minDiffInBST(TreeNode* root) {
        fun(root);
        int ret = INT_MAX;
        for (int i = 1 ; i < m_array.size(); i++)
        {
            ret = min(ret, (m_array[i] - m_array[i - 1]));
        }
        return ret;
    }
};
```