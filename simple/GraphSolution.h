#ifndef __GRAPH_SOLUTION_H__
#define __GRAPH_SOLUTION_H__

#include "common.h"

/*
 *	Base ���·������ *
 *	(1) DFS/BFS ����������·����
 *  (2) Dijkstra�㷨 ����Դ�����·����
 *  (3) Floyd-Warshall�����������ڵ�֮������·����
 *  https://www.cnblogs.com/lxt1105/p/6476379.html
*/

vector<int> minDistance_dfs(vector<vector<int>> graph, int v, int target);





/*
	��С��·����
	https://blog.csdn.net/AAMahone/article/details/90347573

*/


/*
 * ��������
 * https://leetcode.cn/problems/QA2IGt/
 * ����״̬���������������ջ���͹������������ע����ڻ������
 * 
 */
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites);

/*
 * �����������������
 * https://leetcode.cn/problems/maximum-employees-to-be-invited-to-a-meeting/
 * 
*/
int maximumInvitations(vector<int>& favorite);



/*
 * ���
 * https://leetcode.cn/problems/longest-cycle-in-a-graph/
 * ͬ������������ص������һ�
 */

int longestCycle(vector<int>& edges);


 /*
  * ��С��������
  * https://leetcode.cn/problems/path-with-minimum-effort/
  * 
  * dfs?
  *
  */

int minimumEffortPath(vector<vector<int>>& heights);


#endif // !__GRAPH_SOLUTION_H__

