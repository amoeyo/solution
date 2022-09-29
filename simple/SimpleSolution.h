#ifndef __SOLUTION_H__
#define __SOLUTION_H__


#include "common.h"

/* 简单模拟 */

/* 两数之和 */
vector<int> twoSum(vector<int>& nums, int target);

/* 螺旋打印矩阵 */
vector<int> spiralOrder(vector<vector<int>>& matrix);

/* 最大字典序 */
void nextPermutation(vector<int>& nums);

/* 字符串相乘 */
string multiply(string num1, string num2);



/* 双指针 */

/* 合并两个有序数组 */
vector<int> merge(vector<int> a, vector<int> b);





/* 哈希 */

/** 原地哈希 */

/* 第一个缺失的正整数 */
int firstMissingPositive(vector<int>& nums);



/* 二分法 */

/* 查找排序数组中重复元素的位置 */
vector<int> searchRange(vector<int>& nums, int target);



/* 单调栈 */
/*
 *  去除重复字符
 *  https://leetcode.cn/problems/remove-duplicate-letters/
 */
string removeDuplicateLetters(string s);

/*
 *  拼接最大数
 *  https://leetcode.cn/problems/create-maximum-number/
 */
vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k);


/* 滑动窗口 */
/*
 *  最大滑：采摘水果
 *  https://leetcode.cn/problems/fruit-into-baskets/
 */

int totalFruit(vector<int>& fruits);

/* 
 *  最小滑：最小覆盖子串
 *  
 */
string minWindow(string s, string t);

/* 字符串 */

/* KMP算法 */
/*
 *  KMP主要应用在字符串匹配上。
 *  KMP的主要思想是当出现字符串不匹配时，可以知道一部分之前已经匹配的文本内容，
 *  就可以利用这些信息避免从头再去做匹配了。
 * 
 *  文本串和模式串
 *  前缀表：记录下标i之前（包括i）的字符串中，有多大长度的相同前缀后缀
 *  前缀是指不包含最后一个字符的所有以第一个字符开头的连续子串；
 *  后缀是指不包含第一个字符的所有以最后一个字符结尾的连续子串
 *  
 */

/* 获取next数组 */
/* next[i]指不包括当前字符的字符串的最大相同前后缀长度 */
/* 当主串S与模式串P失配时，j=next[j]，P向右移动j - next[j] */
//void getNext(vector<int>& next, string& s)
//{
//	int len = s.size();
//	// j指向前缀末尾
//	int j = -1;
//	// 实际上是初始状态
//	next[0] = j;
//
//	// i指向后缀末尾，同时也指当前判断的子串的长度-1
//	for (int i = 1; i < len; i++)
//	{
//		// 如果s[j + 1] != s[i]，则回退，next[j]表示j之前的最长公共前后缀
//		// i在前进过程中遇到与前缀末尾j不匹配的字符，会导致前缀末尾j直接被撞回去
//		// j停下来的地方，能保证s[j+1]是等于s[i]的，能保证此时以[0, j+1] = [i-(j + 1) ,i]
//		while (j >= 0 && s[j + 1] != s[i])
//		{
//			// 状态回退
//			j = next[j];
//		}
//		if (s[j + 1] == s[i])
//		{
//			// 匹配则前缀末尾后移
//			j++;
//		}
//		// s[j + 1] = s[i]的情况，next[i] + 1就是最长长度
//		// 否则就是-1 + 1 = 0
//		next[i] = j;
//	}
//}

/* 查找子串 */
int strStr(string haystack, string needle);

/* 栈和队列 */

/* 滑动窗口内的最大值 */
/**  单调队列 */
vector<int> maxSlidingWindow(vector<int>& nums, int k);

/* 哈希 */
/** 原地哈希 */
/** 缺失的两个正数 */
vector<int> missingTwo(vector<int>& nums);


/* 贪心 */
/** 最大摆动序列 */
int wiggleMaxLength(vector<int>& nums);

#endif // __SOLUTION_H__