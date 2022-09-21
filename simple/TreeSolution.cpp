#include "TreeSolution.h"


/* createTree */
TreeNode* createTree(vector<int>& nodes)
{
	if (nodes.empty()) return nullptr;
	TreeNode* root = new TreeNode(nodes[0]);
	queue<TreeNode*> node_queue;
	int size = nodes.size();
	node_queue.push(root);
	
	int index = 1;
	while (!node_queue.empty() && index < size)
	{
		TreeNode* curParent = node_queue.front();
		if (curParent)
		{
			if (index < size)
			{
				curParent->left = (nodes[index] == INF) ? nullptr : new TreeNode(nodes[index]);
				index++;
			}
			if (index < size)
			{
				curParent->right = (nodes[index] == INF) ? nullptr : new TreeNode(nodes[index]);
				index++;
			}
			node_queue.push(curParent->left);
			node_queue.push(curParent->right);
		}
		node_queue.pop();
	}
	return root;
}

//非递归
vector<int> postOrderTraverse(TreeNode* root)
{
	if (!root) return { };
	stack<TreeNode*> preOderStack;
	stack<TreeNode*> outStack;

	preOderStack.push(root);
	while (!preOderStack.empty())
	{
		TreeNode* node = preOderStack.top();
		preOderStack.pop();
		outStack.push(node);
		if (node->left) preOderStack.push(node->left);
		if (node->right) preOderStack.push(node->right);
	}
	
	vector<int> res;
	while (!outStack.empty())
	{
		res.push_back(outStack.top()->val);
		outStack.pop();
	}
	return res;

}

TreeNode* createTree(vector<int>& inorder, vector<int>& postorder,
	int inorderL, int inorderR, int postL, int postR)
{
	if (inorderL > inorderR || postL > postR)
	{
		return nullptr;
	}

	TreeNode* root = new TreeNode(postorder[postR]);
	int rootIndex = inorderL;
	for ( ; rootIndex <= inorderR; rootIndex++)
	{
		if (inorder[rootIndex] == postorder[postR])
			break;
	}
	int leftSubTree = rootIndex - inorderL;
	int rightSubTree = inorderR - rootIndex;
	root->left = createTree(inorder, postorder,
		inorderL, rootIndex - 1, postL, postL + leftSubTree - 1);
	root->right = createTree(inorder, postorder,
		rootIndex + 1, inorderR, postL + leftSubTree, postR - 1);
	return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
{
	TreeNode* root = createTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
	return root;
}

//递归，更新每个节点的最大贡献值和最大路径和
int maxPathSum_recursion(TreeNode* curNode, int& max_sum)
{
	if (!curNode)
		return 0;
	//更新最大贡献值和当前最大路径和
	int sum = curNode->val;

	int left = 0, right = 0;
	if (curNode->left)
		left = maxPathSum_recursion(curNode->left, max_sum);

	if (curNode->right)
		right = maxPathSum_recursion(curNode->right, max_sum);
	
	if (left > 0)
	{
		sum += left;
	}
	if (right > 0)
	{
		sum += right;
	}

	if (sum > max_sum)
		max_sum = sum;

	int max_add = max(left, right);
	if(max_add > 0)
		curNode->val += max_add;
	return curNode->val;
}

/* 最大路径和 */
int maxPathSum(TreeNode* root)
{
	int res_sum = root->val;
	int res = maxPathSum_recursion(root, res_sum);
	
	if (res > res_sum)
		return res;

	return res_sum;
}

void getNumbers(TreeNode* root, vector<vector<int>>& nums, vector<int>& path)
{
	if (!root) return;
	if (!root->left && !root->right)
	{
		path.push_back(root->val);
		nums.push_back(path);
		path.pop_back();
		return;
	}
	path.push_back(root->val);
	getNumbers(root->left, nums, path);
	getNumbers(root->right, nums, path);
	path.pop_back();
	return;
}

int sumNumbers(TreeNode* root) 
{
	vector<vector<int>> nums;
	vector<int> path;
	getNumbers(root, nums, path);
	int size = nums.size();
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		int path_len = nums[i].size();
		int path_num = 0;
		for (int j = 0; j < path_len; j++)
		{
			path_num = path_num * 10 + nums[i][j];
		}
		sum += path_num;
	}
	return sum;

}

