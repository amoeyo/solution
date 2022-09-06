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

/*
 *  接雨水
 *  https://leetcode.cn/problems/trapping-rain-water/
 *  记录柱子i左边最高的柱子和右边最高的柱子，柱子i可以接的水由两者间较小的那个与柱子i的高度差决定
 *  dp体现在求left_highest的过程
 */
int trap(vector<int>& height);

/*
 *  剪绳子||
 * https://leetcode.cn/problems/jian-sheng-zi-ii-lcof/?favorite=xb9nqhhg
 * 
 */

int cuttingRope(int n);


#endif // !__DPSOLUTION_H__

