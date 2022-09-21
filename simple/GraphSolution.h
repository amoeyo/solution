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
 * ���鼯
 * https://lfool.github.io/LFool-Notes/algorithm/%E5%B9%B6%E6%9F%A5%E9%9B%86-Union-Find.html
 * ���ͼ����ͨ��
 */

//���鼯�ӿ�
class UF {
public:
    /* ���캯�����������ڵ��ϵ */
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

    /* ��p��q���ӣ�������һ����ĸ��ڵ�ָ����һ����ĸ��ڵ� */
    void union_p(int p, int q)
    {
        //�ҵ�p�ĸ��ڵ�
        int rootP = find(p);
        //�ҵ�q�ĸ��ڵ�
        int rootQ = find(q);
        //����Ѿ���ͨ��������
        if (rootP == rootQ) return;
        parent[rootP] = rootQ;
        size[rootQ] += size[rootP];
        //�޸���ͨ��������
        cnt--;
    }

    /* ���ص�ǰ�ڵ�ĸ��ڵ㣬���ڵ����ԣ��Լ�ָ���Լ� */
    int find(int x)
    {
        if (x != parent[x])
        {
            //x = parent[x];
            //·��ѹ��
            parent[x] = find(parent[x]);
        }
        return parent[x];
        //return x;
    }

    /* �ж�p��q�Ƿ���ͨ����������ͬ�ĸ��ڵ� */
    bool connected(int p, int q)
    {
        p = find(p);
        q = find(q);
        return p == q;
    }

    /* ����ͼ���ж��ٸ���ͨ���� */
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
 *  ͳ������ͼ���޷����ൽ��ĵ������
 *  https://leetcode.cn/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/
 * 
 */
long long countPairs(int n, vector<vector<int>>& edges);


 /*
  * ��С��������
  * https://leetcode.cn/problems/path-with-minimum-effort/
  * 
  * ���鼯����������·������С�������򣬼��뵽���鼯��
  * ���ȨֵΪx�ı߼�������ʹ���Ͻǵĵ㣨idx = 0�������½ǵĵ㣨idx = mn * mn����ͨ����xΪ���
  * ��С������Ҳ����������������
  *
  */

int minimumEffortPath(vector<vector<int>>& heights);


#endif // !__GRAPH_SOLUTION_H__

