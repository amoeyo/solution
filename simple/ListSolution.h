#ifndef __LIST_SOLUTION_H__
#define __LIST_SOLUTION_H__

#include "common.h"

class ListNode
{
public:
	ListNode(int val)
		: val(val), next(nullptr)
	{

	}
	int val;
	ListNode* next;
};


ListNode* createList(vector<int>& nums);

/*
 *  找链表中点
 *  https://leetcode.cn/problems/middle-of-the-linked-list/
 */
ListNode* middleNode(ListNode* head);

 /*
  *  反转链表
  *  https://leetcode.cn/problems/reverse-linked-list/
  */
ListNode* reverseList(ListNode* head);

/*
 *  重排链表
 *  https://leetcode.cn/problems/reorder-list/
 */
void reorderList(ListNode* head);

/*
 *  删除重复元素
 */
ListNode* deleteDuplicates(ListNode* head);

#endif // !__LIST_SOLUTION_H__

