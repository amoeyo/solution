#include "GraphSolution.h"


void minDfs(vector<vector<int>> graph, vector<int>& visit, 
	vector<int>& path, int& distance, int& min_distance,
	int curV, int targetV)
{
	if (curV == targetV)
	{
		path.push_back(curV);
		if (min_distance < distance)
		{
			min_distance = distance;
		}
		path.pop_back();
		return;
	}

	for (int i = 0; i < graph.size(); i++)
	{
		if (i != curV && !visit[i] && graph[curV][i] != INF)
		{
			path.push_back(curV);
			visit[i] = true;
			distance += graph[curV][i];
			minDfs(graph, visit, path, distance, min_distance, i, targetV);
			distance -= graph[curV][i];
			visit[i] = false;
			path.pop_back();
		}
	}
}

vector<int> minDistance_dfs(vector<vector<int>> graph, int v, int target)
{
	int vNum = graph.size();
	vector<int> visit(vNum, false);
	visit[v] = true;
	int distance = 0;
	int min_distance = MAX_UNIT;
	vector<int> path;

	minDfs(graph, visit, path, distance, min_distance, v, target);

	print<int>(path);
	cout << "min distance: " << min_distance << endl;
	return path;
}



#ifdef SOLUTION_0

void markFree(vector<vector<int>>& prerequisites, vector<int>& visit, queue<int>& queueCourse, int preCourse)
{
	int N = prerequisites.size();
	for (int i = 0; i < N; i++)
	{
		if (prerequisites[i][1] == preCourse)
		{
			visit[prerequisites[i][0]]--;
			if (visit[prerequisites[i][0]] == 0)
			{
				queueCourse.push(prerequisites[i][0]);
			}
		}
	}
	
}
#else

const int FREE = 0;
const int BUSY = 1;
const int DONE = 2;

bool findDfs(vector<vector<int>>& prerequisites, 
		vector<int>& visit, vector<int>& res, int curVex)
{
	visit[curVex] = BUSY;

	//搜索其前置节点
	int N = prerequisites.size();
	for (int i = 0; i < N; i++)
	{
		if (prerequisites[i][0] == curVex)
		{
			if (visit[prerequisites[i][1]] == FREE)
			{
				bool valid = findDfs(prerequisites, visit, res, prerequisites[i][1]);
				if (!valid) return valid;
			}

			if (visit[prerequisites[i][1]] == BUSY)
			{
				return false;
			}

		}
		
	}

	visit[curVex] = DONE;
	res.push_back(curVex);
}

#endif

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
{
	
#ifdef SOLUTION_0 //bfs解法
	vector<int> visit(numCourses, 0);
	int N = prerequisites.size();
	vector<int> resCourse;
	queue<int> queueCourse;
	for (int i = 0; i < N; i++)
	{
		//统计入度
		visit[prerequisites[i][0]]++;
	}


	//所有入度为0的课程加入队列
	for (int i = 0; i < numCourses; i++)
	{
		if (!visit[i])
		{
			queueCourse.push(i);
		}
	}

	while (!queueCourse.empty())
	{
		int course = queueCourse.front();
		queueCourse.pop();
		resCourse.push_back(course);
		//将所有以i为前置课程的课程入度-1
		markFree(prerequisites, visit, queueCourse, course);
	}

	if (resCourse.size() != numCourses)
	{
		return {};
	}

	return resCourse;

#else //dfs解法，三种状态判断环
	vector<int> visit(numCourses, FREE);
	int N = prerequisites.size();
	vector<int> resCourse;
	
	bool valid = false;

	for (int i = 0; i < numCourses; i++)
	{
		if (!visit[i])
		{
			valid = findDfs(prerequisites, visit, resCourse, i);
		}
	}

	if (!valid) return { };
	return resCourse;

#endif
}

//处理链(DFS) 超时，弃用
int dealLink(vector<int>& favorite, vector<bool>& visit, int vexNum, int vex)
{
	int len = 0;
	for (int i = 0; i < vexNum; i++)
	{
		if (!visit[i] && favorite[i] == vex)
		{
			len = max(len, 1 + dealLink(favorite, visit, vexNum, i));
		}
	}
	visit[vex] = true;
	return len;
}

//处理环
int dealCircle(vector<int>& favorite, vector<bool>& visit, int vexNum, int vex)
{
	int len = 1;
	visit[vex] = true;
	int nextVex = favorite[vex];
	while (nextVex != vex)
	{
		visit[nextVex] = true;
		nextVex = favorite[nextVex];
		len++;
	}

	
	return len;
}


int maximumInvitations(vector<int>& favorite)
{
	//拓扑排序的方法找基环
	//BFS方法，统计入度
	int vexNum = favorite.size();
	vector<int> indegree(vexNum, 0);
	queue<int> vexQueue;

	//注意统计入度的方法
	for (int i = 0; i < vexNum; i++)
	{
		indegree[favorite[i]]++;
	}

	//将入度为0的节点入队列
	for (int i = 0; i < vexNum; i++)
	{
		if (indegree[i] == 0)
		{
			vexQueue.push(i);
		}
	}

	vector<bool> visit(vexNum, false);

	//一遍拓扑排序，顺便记录链的最大深度
	vector<int> max_depth(vexNum, 1);
	while (!vexQueue.empty())
	{
		int popVex = vexQueue.front();
		vexQueue.pop();
		
		indegree[favorite[popVex]]--;
		max_depth[favorite[popVex]] = max(1 + max_depth[popVex], max_depth[favorite[popVex]]);

		if (indegree[favorite[popVex]] == 0)
			vexQueue.push(favorite[popVex]);
		
	}

	int circle_len = 0;
	//要注意的是链可以累加
	int link_len = 0;
	int max_len = MIN_UNIT;

	
	for (int i = 0; i < vexNum; i++)
	{
		if (!visit[i] && indegree[i] == 1)
		{
			//处理包含i的环
			int len = dealCircle(favorite, visit, vexNum, i);
			

			if (len == 2)
			{
				//处理链
				//int link_len1 = dealLink(favorite, visit, vexNum, i);
				//int link_len2 = dealLink(favorite, visit, vexNum, favorite[i]);
				int link_len1 = max_depth[i];
				int link_len2 = max_depth[favorite[i]];
				
				len = link_len1 + link_len2;
				link_len += len;
			}
			else
			{
				circle_len = max(circle_len, len);
			}
		}
	}

	max_len = max(link_len, circle_len);

	return max_len;
}


int longestCycle(vector<int>& edges)
{
	int maxCircleLen = 0;
	int vexNum = edges.size();
	vector<int> indegree(vexNum, 0);
	

	for (int i = 0; i < vexNum; i++)
	{
		if (edges[i] != -1)
			indegree[edges[i]]++;
	}

	queue<int> vexQueue;
	for (int i = 0; i < vexNum; i++)
	{
		if (indegree[i] == 0)
		{
			vexQueue.push(i);
		}
	}

	while (!vexQueue.empty())
	{
		int vex = vexQueue.front();
		vexQueue.pop();

		if (edges[vex] != -1)
			indegree[edges[vex]]--;
		else
			continue;

		if (indegree[edges[vex]] == 0)
		{
			vexQueue.push(edges[vex]);
		}
	}

	for (int i = 0; i < vexNum; i++)
	{
		if (indegree[i] == 1)
		{
			int circle_len = 1;
			indegree[i] = -1;
			int next = edges[i];
			while (next != i)
			{
				indegree[next] = -1;
				next = edges[next];
				circle_len++;
			}
			if (maxCircleLen < circle_len)
			{
				maxCircleLen = circle_len;
			}
		}
	}


	return maxCircleLen;
}

long long countPairs(int n, vector<vector<int>>& edges)
{
	UF union_set(n);
	int size = edges.size();
	for (int i = 0; i < size; i++)
	{
		union_set.union_p(edges[i][0], edges[i][1]);
	}

	long long pair_count = 0;
	for (int i = 0; i < n; i++)
	{
		if (union_set.is_parent(i))
		{
			pair_count += (long long)union_set.size_n(i) * (n - union_set.size_n(i));
		}
	}
	return pair_count / 2;
}

int minHeightRes = MAX_UNIT;
bool flag = false;

//void minimunEffortPath_dfs(vector<vector<int>>& heights, int& maxH, int preH, int x, int y)
//{
//	if ((x == heights.size() - 1) && (y == heights[0].size() - 1))
//	{
//		int h = abs(heights[x][y] - preH);
//		if (h > maxH)
//		{
//			maxH = h;
//		}
//
//		if (minHeightRes > maxH)
//		{
//			minHeightRes = maxH;
//		}
//		return;
//	}
//	if (x >= heights.size() || y >= heights[0].size())
//	{
//		return;
//	}
//	if (x < 0 || y < 0)
//	{
//		return;
//	}
//
//	if (heights[x][y] != -1)
//	{
//		int pre_height = heights[x][y];
//		
//		int h = abs(pre_height - preH);
//		if (h > maxH)
//		{
//			maxH = h;
//		}
//		if (maxH > minHeightRes) return;
//
//		heights[x][y] = -1;
//
//		minimunEffortPath_dfs(heights, maxH, pre_height, x + 1, y);
//		minimunEffortPath_dfs(heights, maxH, pre_height, x - 1, y);
//		minimunEffortPath_dfs(heights, maxH, pre_height, x, y + 1);
//		minimunEffortPath_dfs(heights, maxH, pre_height, x, y - 1);
//
//		heights[x][y] = pre_height;
//	}
//	else
//	{
//		return;
//	}
//
//	
//}

int minimumEffortPath(vector<vector<int>>& heights)
{
	int rowNum = heights.size();
	int colNum = heights[0].size();
	
	int maxH = -1;

	int num = rowNum * colNum;

	
	

	return minHeightRes;
}