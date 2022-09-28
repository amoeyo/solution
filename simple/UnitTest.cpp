#include "UnitTest.h"

void print_list(ListNode* head)
{
	ListNode* p = head;
	while (p)
	{
		cout << p->val << " ";
		p = p->next;
	}
}

template<typename T>
void print_vector(vector<T> nums)
{
	auto it = nums.begin();
	while (it != nums.end())
	{
		cout << *it << " ";
		it++;
	}
}


void UT_DeleteDuplication()
{
	vector<int> testVec = { 1,2,3,3,4,4,5 };
	ListNode* head = createList(testVec);
	
	ListNode* resList = deleteDuplicates(head);
	print_list(resList);
}

void UT_NextPermutation()
{
	vector<int> testVec = { 1,5,1 };

	nextPermutation(testVec);
	print_vector<int>(testVec);
}

void UT_GenerateParenthesis()
{
	int n = 3;
	vector<string> testVec = generateParenthesis(n);
	print_vector<string>(testVec);
}

void UT_LongestCommonSubsequence()
{
	string str1 = "bsbininm";
	string str2 = "jmjkbkjkv";
	int res = longestCommonSubsequence(str1, str2);
	cout << res;
}

void UT_FirstMissingPositive()
{
	vector<int> testVec = { 3,4,-1,1 };
	int res = firstMissingPositive(testVec);
	cout << res;
}

void UT_MinWindow()
{
	string s = "ADOBECODEBANC";
	string t = "ABC";
	string res = minWindow(s, t);
	cout << res;
}

void UT_CoinChange()
{
	vector<int> coins = { 1,2,5};
	int amount = 11;
	int res = coinChange(coins, amount);
	cout << res;
}

void UT_SumNumbers()
{
	vector<int> tree = { 4,9,0,5,1 };
	TreeNode* root = createTree(tree);
	int res = sumNumbers(root);
	cout << res;
}

void UT_Multiply()
{
	string num1 = "123";
	string num2 = "456";
	string res = multiply(num1, num2);
	cout << res;
}

void UT_RemoveDuplicateLetters()
{
	string s = "ecbacba";
	string res = removeDuplicateLetters(s);
	cout << res;
}

void UT_SearchRange()
{
	vector<int> nums = { 5,7,7,8,8,10 };
	int target = 8;
	vector<int> res = searchRange(nums, target);
	print<int>(res);
}

void UT_TotalFruit()
{
	vector<int> fruit = { 1,0,1,4,1,4,1,2,3 };
	int res = totalFruit(fruit);
	cout << res;
}

void UT_MaxNumber()
{
	vector<int> num1 = { 2,5,6,4,4,0};
	vector<int> num2 = {7,3,8,0,6,5,7,6,2};
	int k = 15;
	vector<int> res = maxNumber(num1, num2, k);
	
	print<int>(res);
}

void UT_StrStr()
{
	string haystack = "leetcode";
	string needle = "leeto";
	int res = strStr(haystack, needle);
	cout << res;
}

void UT_MaxSlidingWindow()
{
	vector<int> nums = { 1,3,1,2,0,5 };
	int k = 3;
	vector<int> res = maxSlidingWindow(nums, k);
	print<int>(res);

}

void UT_TreeStackTraverse()
{

}

void UT_MissingTwo()
{
	vector<int> nums = {1,3,4,5,6,7,8,9};
	vector<int> res = missingTwo(nums);
	print<int>(res);
}

void UT_ConstructMaximumBinaryTree()
{
	vector<int> nums = { 3,2,1,6,0,5 };
	TreeNode* root = constructMaximumBinaryTree(nums);
	vector<int> res = inOrderTraverseStack(root);
	print<int>(res);
}

void UT_LowestCommonAncestor()
{
	vector<int> nums = { 1, 2 };
	TreeNode* root = createTree(nums);
	TreeNode* p = getNode(root, 1);
	TreeNode* q = getNode(root, 2);
	TreeNode* node = lowestCommonAncestor(root, p, q);
	cout << node->val;
}

void UT_DeleteNode()
{
	vector<int> nums = { 5,3,7,INF,4,6,8 };
	TreeNode* root = createTree(nums);
	vector<int> tree = inOrderTraverseStack(root);
	print<int>(tree);
	root = deleteNode(root, 5);
	vector<int> res = inOrderTraverseStack(root);
	print<int>(res);

}

void UT_MaxProfit()
{
	vector<int> prices = { 7,1,5,3,6,4 };
	int maxP = maxProfit(prices);
	cout << maxP;
}
