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
 *  �������е�
 *  https://leetcode.cn/problems/middle-of-the-linked-list/
 */
ListNode* middleNode(ListNode* head);

 /*
  *  ��ת����
  *  https://leetcode.cn/problems/reverse-linked-list/
  */
ListNode* reverseList(ListNode* head);

/*
 *  ��������
 *  https://leetcode.cn/problems/reorder-list/
 */
void reorderList(ListNode* head);

/*
 *  ɾ���ظ�Ԫ��
 */
ListNode* deleteDuplicates(ListNode* head);

#endif // !__LIST_SOLUTION_H__

