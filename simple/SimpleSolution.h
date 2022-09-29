#ifndef __SOLUTION_H__
#define __SOLUTION_H__


#include "common.h"

/* ��ģ�� */

/* ����֮�� */
vector<int> twoSum(vector<int>& nums, int target);

/* ������ӡ���� */
vector<int> spiralOrder(vector<vector<int>>& matrix);

/* ����ֵ��� */
void nextPermutation(vector<int>& nums);

/* �ַ������ */
string multiply(string num1, string num2);



/* ˫ָ�� */

/* �ϲ������������� */
vector<int> merge(vector<int> a, vector<int> b);





/* ��ϣ */

/** ԭ�ع�ϣ */

/* ��һ��ȱʧ�������� */
int firstMissingPositive(vector<int>& nums);



/* ���ַ� */

/* ���������������ظ�Ԫ�ص�λ�� */
vector<int> searchRange(vector<int>& nums, int target);



/* ����ջ */
/*
 *  ȥ���ظ��ַ�
 *  https://leetcode.cn/problems/remove-duplicate-letters/
 */
string removeDuplicateLetters(string s);

/*
 *  ƴ�������
 *  https://leetcode.cn/problems/create-maximum-number/
 */
vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k);


/* �������� */
/*
 *  ��󻬣���ժˮ��
 *  https://leetcode.cn/problems/fruit-into-baskets/
 */

int totalFruit(vector<int>& fruits);

/* 
 *  ��С������С�����Ӵ�
 *  
 */
string minWindow(string s, string t);

/* �ַ��� */

/* KMP�㷨 */
/*
 *  KMP��ҪӦ�����ַ���ƥ���ϡ�
 *  KMP����Ҫ˼���ǵ������ַ�����ƥ��ʱ������֪��һ����֮ǰ�Ѿ�ƥ����ı����ݣ�
 *  �Ϳ���������Щ��Ϣ�����ͷ��ȥ��ƥ���ˡ�
 * 
 *  �ı�����ģʽ��
 *  ǰ׺����¼�±�i֮ǰ������i�����ַ����У��ж�󳤶ȵ���ͬǰ׺��׺
 *  ǰ׺��ָ���������һ���ַ��������Ե�һ���ַ���ͷ�������Ӵ���
 *  ��׺��ָ��������һ���ַ������������һ���ַ���β�������Ӵ�
 *  
 */

/* ��ȡnext���� */
/* next[i]ָ��������ǰ�ַ����ַ����������ͬǰ��׺���� */
/* ������S��ģʽ��Pʧ��ʱ��j=next[j]��P�����ƶ�j - next[j] */
//void getNext(vector<int>& next, string& s)
//{
//	int len = s.size();
//	// jָ��ǰ׺ĩβ
//	int j = -1;
//	// ʵ�����ǳ�ʼ״̬
//	next[0] = j;
//
//	// iָ���׺ĩβ��ͬʱҲָ��ǰ�жϵ��Ӵ��ĳ���-1
//	for (int i = 1; i < len; i++)
//	{
//		// ���s[j + 1] != s[i]������ˣ�next[j]��ʾj֮ǰ�������ǰ��׺
//		// i��ǰ��������������ǰ׺ĩβj��ƥ����ַ����ᵼ��ǰ׺ĩβjֱ�ӱ�ײ��ȥ
//		// jͣ�����ĵط����ܱ�֤s[j+1]�ǵ���s[i]�ģ��ܱ�֤��ʱ��[0, j+1] = [i-(j + 1) ,i]
//		while (j >= 0 && s[j + 1] != s[i])
//		{
//			// ״̬����
//			j = next[j];
//		}
//		if (s[j + 1] == s[i])
//		{
//			// ƥ����ǰ׺ĩβ����
//			j++;
//		}
//		// s[j + 1] = s[i]�������next[i] + 1���������
//		// �������-1 + 1 = 0
//		next[i] = j;
//	}
//}

/* �����Ӵ� */
int strStr(string haystack, string needle);

/* ջ�Ͷ��� */

/* ���������ڵ����ֵ */
/**  �������� */
vector<int> maxSlidingWindow(vector<int>& nums, int k);

/* ��ϣ */
/** ԭ�ع�ϣ */
/** ȱʧ���������� */
vector<int> missingTwo(vector<int>& nums);


/* ̰�� */
/** ���ڶ����� */
int wiggleMaxLength(vector<int>& nums);

#endif // __SOLUTION_H__