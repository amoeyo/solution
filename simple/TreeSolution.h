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

/* �漰��������Ŀһ�������ֽⷨ 
 * 1. �ݹ�
 * *  ȷ���ݹ�����ͷ���ֵ
 * *  ȷ����ֹ����
 * *  ȷ������ݹ���߼�
 *  
 * 2. ����
 * *  ջ�Ͷ���
*/

/* �ǵݹ��ǰ�к������ */
vector<int> preOrderTraverseStack(TreeNode* root);
vector<int> inOrderTraverseStack(TreeNode* root);
vector<int> postOrderTraverseStack(TreeNode* root);

TreeNode* getNode(TreeNode* root, int val);

/* �������߶� */


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

/*
 *  ��������
 *  https://leetcode.cn/problems/maximum-binary-tree/
 */
TreeNode* constructMaximumBinaryTree(vector<int>& nums);


/*
 *  �ϲ�������
 *  
 */
TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2);

/*
 *  �����������
 *  https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/
 */
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);

/*
 *  ɾ��ƽ��������Ľ��
 *
 */
TreeNode* deleteNode(TreeNode* root, int key);

/*
 *  �ۼ���
 *  https://leetcode.cn/problems/convert-bst-to-greater-tree/
 */
TreeNode* convertBST(TreeNode* root);

#endif // !__TREE_SOLUTION_H__

