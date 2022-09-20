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

#endif // !__TREE_SOLUTION_H__

