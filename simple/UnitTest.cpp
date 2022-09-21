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