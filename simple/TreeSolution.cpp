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

TreeNode* getNode(TreeNode* root, int val)
{
	if (!root) return nullptr;
	if (root->val == val) return root;
	TreeNode* left = getNode(root->left, val);
	TreeNode* right = getNode(root->right, val);
	return (left != nullptr) ? left : ((right != nullptr) ? right : nullptr);
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

vector<int> preOrderTraverseStack(TreeNode* root)
{
	if (!root) return {};
	vector<int> res;
	stack<TreeNode*> nodeStack;
	
	nodeStack.push(root);
	while (!nodeStack.empty())
	{
		TreeNode* node = nodeStack.top();
		res.push_back(node->val);
		nodeStack.pop();
		if (node->right) nodeStack.push(node->right);
		if (node->left) nodeStack.push(node->left);
	}
	return res;
}

vector<int> inOrderTraverseStack(TreeNode* root)
{
	if (!root) return {};
	vector<int> res;
	stack<TreeNode*> nodeStack;
	TreeNode* cur = root;
	while (cur || !nodeStack.empty())
	{
		if (cur)
		{
			nodeStack.push(cur);
			cur = cur->left;
		}
		else
		{
			cur = nodeStack.top();
			res.push_back(cur->val);
			nodeStack.pop();
			cur = cur->right;
		}	
	}
	return res;
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

TreeNode* constructTree(vector<int>& nums, int left, int right)
{
	if (left < 0 || right >= nums.size() || left > right) return nullptr;
	int max_num = nums[left];
	int cur = left;
	for (int index = left + 1; index <= right; index++)
	{
		if (nums[index] > max_num)
		{
			max_num = nums[index];
			cur = index;
		}
	}
	TreeNode* node = new TreeNode(max_num);
	node->left = constructTree(nums, left, cur - 1);
	node->right = constructTree(nums, cur + 1, right);
	return node;
}

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
	TreeNode* root = constructTree(nums, 0, nums.size() - 1);
	return root;
}

TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) 
{
	if (!root1 && !root2) return nullptr;
	if (!root1 && root2) return root2;
	if (root1 && !root2) return root1;
	root1->val += root2->val;
	root1->left = mergeTrees(root1->left, root2->left);
	root1->right = mergeTrees(root1->right, root2->left);
	return root1;
}

bool isExist(TreeNode* root, TreeNode* p)
{
	if (!root) return false;
	if (root == p) return true;
	return isExist(root->left, p) || isExist(root->right, p);
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
	if (!root) return nullptr;
	bool pLeftExist = isExist(root->left, p);
	bool pRightExist = isExist(root->right, p);
	bool qLeftExist = isExist(root->left, q);
	bool qRightExist = isExist(root->right, q);

	if (((root == p) && (qLeftExist || qRightExist))
			|| ((root == q) && (pLeftExist || pRightExist))
			|| (pLeftExist && qRightExist)
			|| (pRightExist && qLeftExist))
		return root;
	TreeNode* node = nullptr;
	if (pLeftExist && qLeftExist) node = lowestCommonAncestor(root->left, p, q);
	if (pRightExist && qRightExist) node = lowestCommonAncestor(root->right, p, q);
	if (node) return node;
	return nullptr;
	
}

TreeNode* deleteNode(TreeNode* root, int key)
{
	if (!root) return nullptr;
	if (key < root->val)
	{
		root->left = deleteNode(root->left, key);
	}
	else if (key > root->val)
	{
		root->right = deleteNode(root->right, key);
	}
	else
	{
		if (root->left && root->right)
		{
			TreeNode* cur = root->right;
			while (cur->left)
			{
				cur = cur->left;
			}
			swap(root->val, cur->val);
			root->right = deleteNode(root->right, key);
		}
		else if (root->left)
		{
			return root->left;
		}
		else if (root->right)
		{
			return root->right;
		}
		else //叶子结点
		{
			root = nullptr;
		}
	}
	
	return root;
}

TreeNode* convertBST(TreeNode* root)
{
	stack<TreeNode*> node_stack;
	vector<TreeNode*> result_vec;
	TreeNode* cur = root;
	//node_stack.push(cur);
	while (cur || !node_stack.empty())
	{
		if (cur)
		{
			node_stack.push(cur);
			cur = cur->left;
		}
		else
		{
			cur = node_stack.top();
			result_vec.push_back(cur);
			node_stack.pop();
			cur = cur->right;
		}
	}
	reverse(result_vec.begin(), result_vec.end());
	auto it = result_vec.begin();
	int sum = 0;
	while (it != result_vec.end())
	{
		sum += (*it)->val;
		(*it)->val = sum;
		it++;
	}
	return root;
}