#ifndef __DPSOLUTION_H__
#define __DPSOLUTION_H__
#include "common.h"


/*
 * 编辑距离
 * 
 * https://leetcode.cn/problems/edit-distance/
 * 
 * D[i][j] = min(D[i][j−1]+1,D[i−1][j]+1,D[i−1][j−1]) = 1+min(D[i][j−1],D[i−1][j],D[i−1][j−1]−1)
 */
int minDistance(string word1, string word2);

/*
 * 最长严格递增子序列
 * 
 * https://leetcode.cn/problems/longest-increasing-subsequence/
 */
int lengthOfLIS(vector<int>& nums);





#endif // !__DPSOLUTION_H__

