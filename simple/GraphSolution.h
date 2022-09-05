#ifndef __GRAPH_SOLUTION_H__
#define __GRAPH_SOLUTION_H__

#include "common.h"

/*
 *	Base 最短路径问题 *
 *	(1) DFS/BFS （两点间最短路径）
 *  (2) Dijkstra算法 （单源点最短路径）
 *  (3) Floyd-Warshall（任意两个节点之间的最短路径）
 *  https://www.cnblogs.com/lxt1105/p/6476379.html
*/

vector<int> minDistance_dfs(vector<vector<int>> graph, int v, int target);





/*
	最小环路问题
	https://blog.csdn.net/AAMahone/article/details/90347573

*/


/*
 * 拓扑排序
 * https://leetcode.cn/problems/QA2IGt/
 * 三种状态，深度优先搜索（栈）和广度优先搜索，注意存在环的情况
 * 
 */
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites);

/*
 * 拓扑排序，内向基环树
 * https://leetcode.cn/problems/maximum-employees-to-be-invited-to-a-meeting/
 * 
*/
int maximumInvitations(vector<int>& favorite);



/*
 * 最长环
 * https://leetcode.cn/problems/longest-cycle-in-a-graph/
 * 同内向基环树，重点在于找环
 */

int longestCycle(vector<int>& edges);


 /*
  * 最小体力消耗
  * https://leetcode.cn/problems/path-with-minimum-effort/
  * 
  * dfs?
  *
  */

int minimumEffortPath(vector<vector<int>>& heights);


#endif // !__GRAPH_SOLUTION_H__

