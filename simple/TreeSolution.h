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
 * �����л�������
 */
TreeNode* createTree(vector<int>& nodes);

/*
 *  �������ĺ������
 */
vector<int> postOrderTraverse(TreeNode* root);

/*
 *  ����������ͺ���������������
 *  https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
 */
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder);

/*
 *  ���·����
 *  https://leetcode.cn/problems/binary-tree-maximum-path-sum/
 */

int maxPathSum(TreeNode* root);

/*
 *  ���ڵ㵽Ҷ�ӽ��·�����ֺ�
 *  https://leetcode.cn/problems/sum-root-to-leaf-numbers/
 */
int sumNumbers(TreeNode* root);

#endif // !__TREE_SOLUTION_H__

