#include "GraphSolution.h"


int minDfs(vector<vector<int>> graph, vector<int>& visit, vector<int>& path, int v, int target)
{
	if (v == target)
	{

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

	for (int i = 0; i < vNum; i++)
	{
		if (i != v && !visit[i] && graph[v][i] != INF)
		{
			visit[i] == true;
			distance += minDfs(graph, visit, path, i, target);
			if (distance < min_distance)
			{
				min_distance = distance;
			}
			visit[i] == false;

		}
	}

	print<int>(path);
	cout << "min distance: " << min_distance << endl;

}


