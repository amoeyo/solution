#include "ListSolution.h"

ListNode* createList(vector<int>& nums)
{
	if (nums.empty()) return nullptr;
	ListNode* head = new ListNode(nums[0]);
	ListNode* p = head;
	int len = nums.size();
	for (int i = 1; i < len; i++)
	{
		ListNode* newNode = new ListNode(nums[i]);
		p->next = newNode;
		p = p->next;
	}
	return head;

}

ListNode* middleNode(ListNode* head)
{
	ListNode* slow = head;
	ListNode* fast = head;
	while (fast->next && fast->next->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

ListNode* reverseList(ListNode* head)
{
	if (!head) return nullptr;
	ListNode* pre = nullptr;
	ListNode* cur = head;
	
	while (cur)
	{
		ListNode* next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}

	return pre;
}

ListNode* reverse(ListNode* head)
{
	if (head == nullptr && head->next == nullptr) return head;
	ListNode* newHead = reverse(head->next);
	head->next->next = head;
	head->next = nullptr;
	return newHead;

}

ListNode* reverseList_recursion(ListNode* head)
{
	return reverse(head);
}

void reorderList(ListNode* head)
{
	//找中点
	ListNode* midNode = middleNode(head);

	//反转链表

	ListNode* subListHead = reverseList(midNode->next);

	midNode->next = nullptr;

	//链表重排

	ListNode* p = head;
	ListNode* q = subListHead;

	while (q)
	{
		ListNode* addNode = q;
		q = q->next;
		addNode->next = p->next;
		p->next = addNode;
		p = p->next->next;
	}
	
}

ListNode* deleteDuplicates(ListNode* head)
{
	if (!head) return nullptr;
	ListNode* vhead = new ListNode(-1);
	vhead->next = head;
	ListNode* pre = vhead;
	ListNode* cur = head;
	ListNode* next = head->next;

	while (next)
	{
		if (cur->val == next->val)
		{
			while (next && cur->val == next->val)
			{
				next = next->next;
			}
			pre->next = next;
			cur = next;
			if (next) next = next->next;
		}
		else
		{
			pre = cur;
			cur = next;
			next = next->next;
		}
		
	}
	return vhead->next;
}