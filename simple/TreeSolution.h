#ifndef __TREE_SOLUTION_H__
#define __TREE_SOLUTION_H__

#include "common.h"

struct TreeNode
{
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

	int val;
	TreeNode* left;
	TreeNode* right;
};

/* 涉及到树的题目一般有两种解法 
 * 1. 递归
 * *  确定递归参数和返回值
 * *  确定终止条件
 * *  确定单层递归的逻辑
 *  
 * 2. 迭代
 * *  栈和队列
*/

/* 非递归的前中后序遍历 */
vector<int> preOrderTraverseStack(TreeNode* root);
vector<int> inOrderTraverseStack(TreeNode* root);
vector<int> postOrderTraverseStack(TreeNode* root);

TreeNode* getNode(TreeNode* root, int val);

/* 二叉树高度 */


/*
 * 反序列化二叉树
 */
TreeNode* createTree(vector<int>& nodes);

/*
 *  二叉树的后序遍历
 */
vector<int> postOrderTraverse(TreeNode* root);

/*
 *  从中序遍历和后序遍历构造二叉树
 *  https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
 */
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder);



/*
 *  最大路径和
 *  https://leetcode.cn/problems/binary-tree-maximum-path-sum/
 */

int maxPathSum(TreeNode* root);

/*
 *  根节点到叶子结点路径数字和
 *  https://leetcode.cn/problems/sum-root-to-leaf-numbers/
 */
int sumNumbers(TreeNode* root);

/*
 *  最大二叉树
 *  https://leetcode.cn/problems/maximum-binary-tree/
 */
TreeNode* constructMaximumBinaryTree(vector<int>& nums);


/*
 *  合并二叉树
 *  
 */
TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2);

/*
 *  最近公共祖先
 *  https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/
 */
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);

/*
 *  删除平衡二叉树的结点
 *
 */
TreeNode* deleteNode(TreeNode* root, int key);

/*
 *  累加树
 *  https://leetcode.cn/problems/convert-bst-to-greater-tree/
 */
TreeNode* convertBST(TreeNode* root);

#endif // !__TREE_SOLUTION_H__

