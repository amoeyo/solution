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
 * 并查集
 * https://lfool.github.io/LFool-Notes/algorithm/%E5%B9%B6%E6%9F%A5%E9%9B%86-Union-Find.html
 * 检查图的连通性
 */

//并查集接口
class UF {
public:
    /* 构造函数，构建根节点关系 */
    UF(int n)
        : cnt(n)
    {
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    /* 将p和q连接，将其中一个点的根节点指向另一个点的根节点 */
    void union_p(int p, int q)
    {
        //找到p的根节点
        int rootP = find(p);
        //找到q的根节点
        int rootQ = find(q);
        //如果已经连通，则跳过
        if (rootP == rootQ) return;
        parent[rootP] = rootQ;
        size[rootQ] += size[rootP];
        //修改连通分量总数
        cnt--;
    }

    /* 返回当前节点的根节点，根节点特性：自己指向自己 */
    int find(int x)
    {
        if (x != parent[x])
        {
            //x = parent[x];
            //路径压缩
            parent[x] = find(parent[x]);
        }
        return parent[x];
        //return x;
    }

    /* 判断p和q是否连通，即具有相同的根节点 */
    bool connected(int p, int q)
    {
        p = find(p);
        q = find(q);
        return p == q;
    }

    /* 返回图中有多少个连通分量 */
    int count()
    {
        return cnt;
    }

    int size_n(int v)
    {
        return size[v];
    }

    bool is_parent(int v)
    {
        return parent[v] == v;
    }

private:
    int cnt;
    vector<int> parent;
    vector<int> size;
};

/*
 *  统计无向图中无法互相到达的点的数量
 *  https://leetcode.cn/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/
 * 
 */
long long countPairs(int n, vector<vector<int>>& edges);


 /*
  * 最小体力消耗
  * https://leetcode.cn/problems/path-with-minimum-effort/
  * 
  * 并查集，搜索所有路径，从小到大排序，加入到并查集中
  * 如果权值为x的边加入其中使左上角的点（idx = 0）和右下角的点（idx = mn * mn）连通，则x为结果
  * 最小生成树也可以用这个方法解决
  *
  */

int minimumEffortPath(vector<vector<int>>& heights);


#endif // !__GRAPH_SOLUTION_H__

